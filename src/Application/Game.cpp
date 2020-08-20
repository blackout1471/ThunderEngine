#include "tepch.h"
#include "Game.h"
#include <Graphics/RenderApi.h>
#include "Core/Core.h"
#include <Graphics/Vertice.h>
#include <Graphics/Shaders/OpenGlShaders.h>
#include "Time.h"

namespace ThunderEngine {

	Game::Game() : m_IsRunning(true), m_WindowInstance(nullptr)
	{
        m_WindowInstance = new Application::GameWindow();
	}

	Game::~Game()
	{
		delete m_WindowInstance;
	}

	void Game::Run()
	{
        // Create game window
        TE_ASSERT(m_WindowInstance->CreateGameWindow(800, 600, "yes", nullptr, nullptr), "Window couldn't be created", "", '@');
        TE_LOG_INFO("Window created Width: {0} Height: {1}", std::to_string(m_WindowInstance->GetWindowWidth()) + '@' + std::to_string(m_WindowInstance->GetWindowHeight()), '@');

        m_WindowInstance->MakeContextCurrent(); // Make it the target to draw to

        // Create the API, either CPU | Opengl | DirectX
        Graphics::RenderApi::CreateApi(Graphics::RenderVendor::OpenGL);
        TE_ASSERT(Graphics::RenderApi::GetApi()->Init(), "Could not create initialise renderer context", "", '@');

        // The vertices first square
        Graphics::Vertex2D* v1 = new Graphics::Vertex2D();
        Graphics::Vertex2D* v2 = new Graphics::Vertex2D();
        Graphics::Vertex2D* v3 = new Graphics::Vertex2D();
        Graphics::Vertex2D* v4 = new Graphics::Vertex2D();

        v1->Vertice = glm::vec3(-0.2f, 0.5f, 0.0f);
        v2->Vertice = glm::vec3(-0.2f, -0.5f, 0.0f);
        v3->Vertice = glm::vec3(-0.5f, -0.5f, 0.0f);
        v4->Vertice = glm::vec3(-0.5f, 0.5f, 0.0f);

        v1->Color = glm::vec4(1.f, 0.f, 0.0f, 1.f);
        v2->Color = glm::vec4(0.f, 1.f, 0.0f, 1.f);
        v3->Color = glm::vec4(0.f, 0.f, 1.f, 1.f);
        v4->Color = glm::vec4(1.f, 1.f, 1.f, 1.f);

        Graphics::Vertex2D* v5 = new Graphics::Vertex2D();
        Graphics::Vertex2D* v6 = new Graphics::Vertex2D();
        Graphics::Vertex2D* v7 = new Graphics::Vertex2D();
        Graphics::Vertex2D* v8 = new Graphics::Vertex2D();

        v5->Vertice = glm::vec3(0.8f, 0.5f, 0.0f);
        v6->Vertice = glm::vec3(0.8f, -0.5f, 0.0f);
        v7->Vertice = glm::vec3(0.2f, -0.5f, 0.0f);
        v8->Vertice = glm::vec3(0.2f, 0.5f, 0.0f);

        v5->Color = glm::vec4(0.5f, 0.5f, 0.0f, 1.f);
        v6->Color = glm::vec4(0.5f, 0.5f, 0.0f, 1.f);
        v7->Color = glm::vec4(0.5f, 0.5f, 0.0f, 1.f);
        v8->Color = glm::vec4(0.5f, 0.5f, 0.0f, 1.f);

        // Create the different buffers 
        Graphics::VertexArray* m_Vao = Graphics::RenderApi::GetApi()->CreateVertexArray();
        Graphics::VertexBuffer* m_Vbo = Graphics::RenderApi::GetApi()->CreateVertexBuffer(1000);
        Graphics::IndexBuffer* m_Ibo = Graphics::RenderApi::GetApi()->CreateIndexBuffer(1000 * 6);

        // Bind the vertex array and the vertex buffer
        m_Vao->Bind();
        m_Vbo->Bind();

        // Set layout for the shader
        m_Vbo->SetLayout({
            {0, 3, Graphics::ShaderType::Float, false},
            {1, 4, Graphics::ShaderType::Float, false},
            });

        // Set the buffers for the array
        m_Vao->SetVertexBuffer(m_Vbo);
        m_Vao->SetIndexBuffer(m_Ibo);

        // Set data for vertex buffer
        Graphics::Vertex2D* m_BufferPointer = (Graphics::Vertex2D*)m_Vbo->GetPointer(); // Get pointer to buffer
        
        m_BufferPointer->Vertice = v1->Vertice;
        m_BufferPointer->Color  = v1->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v2->Vertice;
        m_BufferPointer->Color = v2->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v3->Vertice;
        m_BufferPointer->Color = v3->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v4->Vertice;
        m_BufferPointer->Color = v4->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v5->Vertice;
        m_BufferPointer->Color = v5->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v6->Vertice;
        m_BufferPointer->Color = v6->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v7->Vertice;
        m_BufferPointer->Color = v7->Color;
        m_BufferPointer++;

        m_BufferPointer->Vertice = v8->Vertice;
        m_BufferPointer->Color = v8->Color;
        m_BufferPointer++;

        m_Vbo->ReleasePointer(); // release the buffer pointer

        // The shader compiled
        Graphics::Shader* shader = Graphics::RenderApi::GetApi()->CreateShader(
            Shaders::OpenGlShaders::Shader2DVertex, 
            Shaders::OpenGlShaders::Shader2DFragment
        );

        float t1, t2;
        t1 = t2 = Time::GetCurrentProcessTime();

        while (!m_WindowInstance->ShouldWindowClose())
        {
            // Get delta time
            t2 = Time::GetCurrentProcessTime();
            Time::SetDeltaTime(t2 - t1);
            t1 = t2;
            OnUpdate();

            // Clear color buffer and insert blue data
            Graphics::RenderApi::GetApi()->ClearColorBit();
            Graphics::RenderApi::GetApi()->ClearColor(.0, .0, .8, 1.0);

            // Bind shader and send data through, to draw
            shader->Bind();

            // Bind index buffer and draw
            m_Ibo->Bind();
            m_Vao->DrawIndicies(Graphics::RenderPrimitives::Triangles, 12);

            // Swap to the buffer being written to
            m_WindowInstance->SwapBuffers();
            m_WindowInstance->PollEvents(); // Get window events and process
        }
	}
}