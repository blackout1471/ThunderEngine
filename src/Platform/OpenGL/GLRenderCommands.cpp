#include "tepch.h"
#include "GLRenderCommands.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool ThunderEngine::OpenGl::GLRenderCommands::Init()
{
    // Load all OpenGL functions using the glfw loader function
    // If you use SDL you can use: https://wiki.libsdl.org/SDL_GL_GetProcAddress
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "glad failed";
        return false;
    }

    return true;
}

void ThunderEngine::OpenGl::GLRenderCommands::ClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void ThunderEngine::OpenGl::GLRenderCommands::ClearColorBit()
{
    glClear(GL_COLOR_BUFFER_BIT);
}


