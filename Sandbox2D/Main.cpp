#include "../src/Graphics/RenderApi.h"
#include "ThunderEngine.h"


using ThunderEngine::Application::Debug;

int main(void)
{
    // Create new game window
    ThunderEngine::Application::GameWindow* gameWindow = new ThunderEngine::Application::GameWindow();
    gameWindow->CreateWindow(640,320,"Yes", NULL, NULL);
    gameWindow->MakeContextCurrent(); // Make it the target to draw to

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
    -0.5f, -0.5f, 0.0f,
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

    while (!gameWindow->ShouldWindowClose())
    {
        // Clear color buffer and insert blue data
        ThunderEngine::RenderApi::GetApi()->ClearColorBit();
        ThunderEngine::RenderApi::GetApi()->ClearColor(.0, .0, .8, 1.0);

        // Bind shader and send data through, to draw
        shader->Bind();
        ThunderEngine::RenderApi::GetApi()->DrawArray(3);

        // Swap to the buffer being written to
        gameWindow->SwapBuffers();
        gameWindow->PollEvents(); // Get window events and process
    }
    return 0;
}