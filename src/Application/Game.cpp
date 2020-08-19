#include "tepch.h"
#include "Game.h"
#include "../src/Graphics/RenderApi.h"
#include "Core/Core.h"

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
        TE_ASSERT(m_WindowInstance->CreateGameWindow(800, 600, "yes", nullptr, nullptr), "Window couldn't be created");

        m_WindowInstance->MakeContextCurrent(); // Make it the target to draw to

        // Create the API, either CPU | Opengl | DirectX
        ThunderEngine::RenderApi::CreateApi(ThunderEngine::RenderVendor::OpenGL);
        ThunderEngine::RenderApi::GetApi()->Init();

        // Shader code
        const char* vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

        const char* fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";

        // The vertices
        float vertices[] = {
        -0.5f, -0.5f, 0.0f, // color
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
        };
        

        // The VertexArray obj, almost like a list for vertexBuffers
        ThunderEngine::VertexArray* vao = ThunderEngine::RenderApi::GetApi()->CreateVertexArray();
        vao->BindBuffer();

        // Vertex buffer stores vertice data, and sends it to the shader
        ThunderEngine::VertexBuffer* vbo = ThunderEngine::RenderApi::GetApi()->CreateVertexBuffer();
        vbo->BindBuffer();
        vbo->SetData(vertices, sizeof(vertices));

        // What attributes to enable in the shader, and how the data looks
        vao->InsertAttributePointer(0, 3, ThunderEngine::ShaderType::Float, false, 3 * sizeof(float), (void*)0);
        vao->EnablePointer(0);

        // The shader compiled
        ThunderEngine::Shader* shader = ThunderEngine::RenderApi::GetApi()->CreateShader(vertexShaderSource, fragmentShaderSource);

        while (!m_WindowInstance->ShouldWindowClose())
        {
            // Clear color buffer and insert blue data
            ThunderEngine::RenderApi::GetApi()->ClearColorBit();
            ThunderEngine::RenderApi::GetApi()->ClearColor(.0, .0, .8, 1.0);

            // Bind shader and send data through, to draw
            shader->Bind();
            ThunderEngine::RenderApi::GetApi()->DrawArray(3);

            // Swap to the buffer being written to
            m_WindowInstance->SwapBuffers();
            m_WindowInstance->PollEvents(); // Get window events and process
        }
	}
}