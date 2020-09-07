#include "tepch.h"
#include "Renderer2D.h"
#include <Graphics/Shaders/OpenGlShaders.h>
#include <entt.hpp>
#include <Entity/Components.h>
#include <Entity/SceneManager.h>

namespace ThunderEngine {
	namespace System {
		
		Renderer2D::Renderer2D()
		{
		}

		Renderer2D::~Renderer2D()
		{
		}

		void Renderer2D::OnStart()
		{
			// Create image
			uint32_t whiteColor = 0xffffffff; // White image
			this->m_FlatTexture = Graphics::RenderApi::GetApi()->CreateTexture(&whiteColor, Graphics::TextureProperties(1, 1, 3));

			m_Textures = std::map<std::string, Graphics::Texture*>();

			// Create the different buffers 
			this->m_Vao = Graphics::RenderApi::GetApi()->CreateVertexArray();
			this->m_Vbo = Graphics::RenderApi::GetApi()->CreateVertexBuffer(5000);
			this->m_Ibo = Graphics::RenderApi::GetApi()->CreateIndexBuffer(5000 * 6);

			// Bind the vertex array and the vertex buffer
			this->m_Vao->Bind();
			this->m_Vbo->Bind();

			// Set layout for the shader
			this->m_Vbo->SetLayout({
				{0, 3, Graphics::ShaderType::Float, false},
				{1, 4, Graphics::ShaderType::Float, false},
				{2, 2, Graphics::ShaderType::Float, false},
				{3, 1, Graphics::ShaderType::Float, false}
				});

			// Set the buffers for the array
			this->m_Vao->SetVertexBuffer(m_Vbo);
			this->m_Vao->SetIndexBuffer(m_Ibo);

			// The shader compiled
			this->m_Shader = Graphics::RenderApi::GetApi()->CreateShader(
				Shaders::OpenGlShaders::Shader2DVertex,
				Shaders::OpenGlShaders::Shader2DFragment
			);
		}

		void Renderer2D::OnUpdate()
		{
			this->m_CurrentScene = Entity::SceneManager::GetScenes()->GetCurrentScene();
		}

		void Renderer2D::OnDraw()
		{
			m_CurrentIndicieCount = 0;

			this->StartSubmit();

			// Submit Quads
			{
				auto renderables = m_CurrentScene->GetRegistry().view<Component::QuadComponent, Component::TransformComponent>();

				for (auto entity : renderables)
				{
					auto& quadComp = renderables.get<Component::QuadComponent>(entity);
					auto& transformComponent = renderables.get<Component::TransformComponent>(entity);
					this->SubmitQuadComponents(quadComp, transformComponent);
				}
			}

			// Submit sprites
			{
				auto renderables = m_CurrentScene->GetRegistry().view<Component::SpriteComponent, Component::TransformComponent>();

				for (auto entity : renderables)
				{
					auto& spriteComponent = renderables.get<Component::SpriteComponent>(entity);
					auto& transformComponent = renderables.get<Component::TransformComponent>(entity);
					this->SubmitSpriteComponents(spriteComponent, transformComponent);
				}
			}

			EndSubmit();

			this->UploadCameraMatrix();

			this->SetTexturesForShader();

			this->DrawIndicies();
		}

		void Renderer2D::UploadCameraMatrix()
		{
			auto cameraView = m_CurrentScene->GetRegistry().view<Component::OrthographicCameraComponent>();
			auto firstEnt = cameraView.front();

			auto& cameraComp = cameraView.get<Component::OrthographicCameraComponent>(firstEnt);

			m_Shader->SetMat4("orthoView", cameraComp.Camera.GetProjection());
		}

		void Renderer2D::SetTexturesForShader()
		{
			// Set texture for quad texture
			this->m_FlatTexture->ActivateTexture(0);
			this->m_FlatTexture->Bind();
			this->m_Shader->Bind();
			this->m_Shader->SetInt("textures[0]", 0);

			// Bind all other textures
			std::map<std::string, Graphics::Texture*>::iterator it = m_Textures.begin();

			int texCount = 1;
			for (std::pair<std::string, Graphics::Texture*> element : m_Textures) {
				element.second->ActivateTexture(texCount);
				element.second->Bind();
				
				std::string textureSlot = std::string("textures[") + std::to_string(texCount) + "]";

				m_Shader->SetInt(textureSlot, texCount);

				texCount++;
			}
		}

		void Renderer2D::DrawIndicies()
		{
			// Clear color buffer and insert blue data
			Graphics::RenderApi::GetApi()->ClearColorBit();
			Graphics::RenderApi::GetApi()->ClearColor(.0, .0, .8, 1.0);

			// Bind index buffer and draw
			m_Ibo->Bind();
			m_Vao->DrawIndicies(Graphics::RenderPrimitives::Triangles, m_CurrentIndicieCount);
		}

		void Renderer2D::StartSubmit()
		{
			m_BufferPointer = (Graphics::Vertex2D*)m_Vbo->GetPointer(); // Get pointer to buffer
		}

		void Renderer2D::EndSubmit()
		{
			m_Vbo->ReleasePointer(); // release the buffer pointer
		}


		void Renderer2D::SubmitSpriteComponents(Component::SpriteComponent& spriteComp, Component::TransformComponent& transComp)
		{
			// Check if texture exist
			if (m_Textures.find(spriteComp.Path) == m_Textures.end())
			{
				Graphics::Texture* curTexture = Graphics::RenderApi::GetApi()->CreateTexture(spriteComp.Path.c_str());

				// not exist
				m_Textures.insert(std::make_pair(spriteComp.Path, curTexture));
			}

			float textureIndex = (float)std::distance(m_Textures.begin(), m_Textures.find(spriteComp.Path));

			glm::mat4 modelMat = transComp.Transform.GetModel();
			m_BufferPointer->Vertice = modelMat * glm::vec4(spriteComp.Width, spriteComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = spriteComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(0.f, 0.f);
			m_BufferPointer->TextureId = textureIndex + 1;
			m_BufferPointer++;

			m_BufferPointer->Vertice = modelMat * glm::vec4(spriteComp.Width, -spriteComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = spriteComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(1.f, 0.f);
			m_BufferPointer->TextureId = textureIndex + 1;
			m_BufferPointer++;

			m_BufferPointer->Vertice = modelMat * glm::vec4(-spriteComp.Width, -spriteComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = spriteComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(1.f, 1.f);
			m_BufferPointer->TextureId = textureIndex + 1;
			m_BufferPointer++;

			m_BufferPointer->Vertice = modelMat * glm::vec4(-spriteComp.Width, spriteComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = spriteComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(0.f, 1.f);
			m_BufferPointer->TextureId = textureIndex + 1;
			m_BufferPointer++;

			m_CurrentIndicieCount += 6;
		}

		void Renderer2D::SubmitQuadComponents(Component::QuadComponent& quadComp, Component::TransformComponent& transComp)
		{
			glm::mat4 modelMat = transComp.Transform.GetModel();
			m_BufferPointer->Vertice = modelMat * glm::vec4(quadComp.Width, quadComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = quadComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(0.f, 0.f);
			m_BufferPointer->TextureId = 0.f;
			m_BufferPointer++;

			m_BufferPointer->Vertice = modelMat * glm::vec4(quadComp.Width, -quadComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = quadComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(1.f, 0.f);
			m_BufferPointer->TextureId = 0.f;
			m_BufferPointer++;

			m_BufferPointer->Vertice = modelMat * glm::vec4(-quadComp.Width, -quadComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = quadComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(1.f, 1.f);
			m_BufferPointer->TextureId = 0.f;
			m_BufferPointer++;

			m_BufferPointer->Vertice = modelMat * glm::vec4(-quadComp.Width, quadComp.Height, -1.f, 1.f);
			m_BufferPointer->Color = quadComp.Color;
			m_BufferPointer->TextureCoordinates = glm::vec2(0.f, 1.f);
			m_BufferPointer->TextureId = 0.f;
			m_BufferPointer++;

			m_CurrentIndicieCount += 6;
		}
	}
}