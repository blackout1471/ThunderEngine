#include "tepch.h"
#include "Scene.h"

#include "Entity.h"

// TODO:: TEST
#include <Graphics/RenderApi.h>
#include <Graphics/Vertice.h>
#include <Graphics/Shaders/OpenGlShaders.h>
#include "Components.h"

namespace ThunderEngine {
	namespace Entity {


		Scene::Scene() // TODO :: Make Render system
		{
			// Create image
			uint32_t whiteColor = 0xffffffff; // White image
			m_FlatTexture = Graphics::RenderApi::GetApi()->CreateTexture(&whiteColor, Graphics::TextureProperties(1, 1, 3));

			// Create the different buffers 
			m_Vao = Graphics::RenderApi::GetApi()->CreateVertexArray();
			m_Vbo = Graphics::RenderApi::GetApi()->CreateVertexBuffer(1000);
			m_Ibo = Graphics::RenderApi::GetApi()->CreateIndexBuffer(1000 * 6);

			// Bind the vertex array and the vertex buffer
			m_Vao->Bind();
			m_Vbo->Bind();

			// Set layout for the shader
			m_Vbo->SetLayout({
				{0, 3, Graphics::ShaderType::Float, false},
				{1, 4, Graphics::ShaderType::Float, false},
				{2, 2, Graphics::ShaderType::Float, false},
				{3, 1, Graphics::ShaderType::Float, false}
				});

			// Set the buffers for the array
			m_Vao->SetVertexBuffer(m_Vbo);
			m_Vao->SetIndexBuffer(m_Ibo);

			// The shader compiled
			m_Shader = Graphics::RenderApi::GetApi()->CreateShader(
				Shaders::OpenGlShaders::Shader2DVertex,
				Shaders::OpenGlShaders::Shader2DFragment
			);

			// Create Entity
			Entity entityOne = Scene::CreateEntity();
			Entity entityTwo = Scene::CreateEntity();
			Entity entityThree = Scene::CreateEntity();

			entityTwo.AddComponent<Component::Test2DQuadComponent>(0.3f, glm::vec4(1.f, 0.f, 0.f, 1.f));
			entityOne.AddComponent<Component::Test2DQuadComponent>(0.5f, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			entityThree.AddComponent<Component::Test2DQuadComponent>(0.7f, glm::vec4(0.f, 1.f, 0.f, 1.0f));
		}


		Scene::~Scene()
		{
		}


		Entity Scene::CreateEntity() {
			Entity entity = { m_Registry.create(), this };
			return entity;
		}

		void Scene::OnUpdate()
		{
			auto renderable = m_Registry.view<Component::Test2DQuadComponent>();

			TE_LOG_INFO("Amount: {}", { static_cast<int>(m_Registry.size()) });

			// Set data for vertex buffer
			Graphics::Vertex2D* m_BufferPointer = (Graphics::Vertex2D*)m_Vbo->GetPointer(); // Get pointer to buffer

			for (auto entity : renderable) {
				auto& test = renderable.get<Component::Test2DQuadComponent>(entity);

				m_BufferPointer->Vertice = test.urc.Vertice;
				m_BufferPointer->Color = test.urc.Color;
				m_BufferPointer->TextureCoordinates = test.urc.TextureCoordinates;
				m_BufferPointer->TextureId = test.urc.TextureId;
				m_BufferPointer++;

				m_BufferPointer->Vertice = test.drc.Vertice;
				m_BufferPointer->Color = test.drc.Color;
				m_BufferPointer->TextureCoordinates = test.drc.TextureCoordinates;
				m_BufferPointer->TextureId = test.drc.TextureId;
				m_BufferPointer++;

				m_BufferPointer->Vertice = test.dlc.Vertice;
				m_BufferPointer->Color = test.dlc.Color;
				m_BufferPointer->TextureCoordinates = test.dlc.TextureCoordinates;
				m_BufferPointer->TextureId = test.dlc.TextureId;
				m_BufferPointer++;

				m_BufferPointer->Vertice = test.ulc.Vertice;
				m_BufferPointer->Color = test.ulc.Color;
				m_BufferPointer->TextureCoordinates = test.ulc.TextureCoordinates;
				m_BufferPointer->TextureId = test.ulc.TextureId;
				m_BufferPointer++;
			}

			m_Vbo->ReleasePointer(); // release the buffer pointer

			// Set texture data
			m_FlatTexture->ActivateTexture(0);
			m_FlatTexture->Bind();

			// Clear color buffer and insert blue data
			Graphics::RenderApi::GetApi()->ClearColorBit();
			Graphics::RenderApi::GetApi()->ClearColor(.0, .0, .8, 1.0);

			// Bind shader and send data through, to draw
			m_Shader->Bind();
			m_Shader->SetInt("textures[0]", 0);

			// Bind index buffer and draw
			m_Ibo->Bind();
			m_Vao->DrawIndicies(Graphics::RenderPrimitives::Triangles, renderable.size() * 12);

		}

	}
}