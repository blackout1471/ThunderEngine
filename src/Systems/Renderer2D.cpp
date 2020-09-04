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
			m_FlatTexture = Graphics::RenderApi::GetApi()->CreateTexture(&whiteColor, Graphics::TextureProperties(1, 1, 3));

			// Create the different buffers 
			m_Vao = Graphics::RenderApi::GetApi()->CreateVertexArray();
			m_Vbo = Graphics::RenderApi::GetApi()->CreateVertexBuffer(5000);
			m_Ibo = Graphics::RenderApi::GetApi()->CreateIndexBuffer(5000 * 6);

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
		}

		void Renderer2D::OnUpdate()
		{
			m_CurrentScene = Entity::SceneManager::GetScenes()->GetCurrentScene();
		}

		void Renderer2D::OnDraw()
		{
			m_CurrentIndicieCount = 0;

			StartSubmit();
			auto renderables = m_CurrentScene->GetRegistry().view<Component::Test2DQuadComponent>();
			
			for (auto entity : renderables)
			{
				auto& component = renderables.get<Component::Test2DQuadComponent>(entity);
				SubmitQuadComponent(component);
			}


			EndSubmit();

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

		void Renderer2D::SubmitQuadComponent(Component::Test2DQuadComponent& component)
		{
			m_BufferPointer->Vertice = component.urc.Vertice;
			m_BufferPointer->Color = component.urc.Color;
			m_BufferPointer->TextureCoordinates = component.urc.TextureCoordinates;
			m_BufferPointer->TextureId = component.urc.TextureId;
			m_BufferPointer++;

			m_BufferPointer->Vertice = component.drc.Vertice;
			m_BufferPointer->Color = component.drc.Color;
			m_BufferPointer->TextureCoordinates = component.drc.TextureCoordinates;
			m_BufferPointer->TextureId = component.drc.TextureId;
			m_BufferPointer++;

			m_BufferPointer->Vertice = component.dlc.Vertice;
			m_BufferPointer->Color = component.dlc.Color;
			m_BufferPointer->TextureCoordinates = component.dlc.TextureCoordinates;
			m_BufferPointer->TextureId = component.dlc.TextureId;
			m_BufferPointer++;

			m_BufferPointer->Vertice = component.ulc.Vertice;
			m_BufferPointer->Color = component.ulc.Color;
			m_BufferPointer->TextureCoordinates = component.ulc.TextureCoordinates;
			m_BufferPointer->TextureId = component.ulc.TextureId;
			m_BufferPointer++;

			m_CurrentIndicieCount += 6;
		}
	}
}