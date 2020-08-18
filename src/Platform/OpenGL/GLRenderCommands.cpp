#include "tepch.h"
#include "GLRenderCommands.h"
#include "GLVertexArray.h"
#include "GLVertexBuffer.h"
#include "GLShader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace ThunderEngine {
    namespace OpenGl {

        void OpenGLMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userparam) {
            std::cout << "Error: " << message << std::endl;
        }


        bool GLRenderCommands::Init()
        {
            // Load all OpenGL functions using the glfw loader function
            // If you use SDL you can use: https://wiki.libsdl.org/SDL_GL_GetProcAddress
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                return false;
            }

#if TE_DEBUG
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(OpenGLMessageCallback, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

            return true;
        }

        void GLRenderCommands::ClearColor(float r, float g, float b, float a)
        {
            glClearColor(r, g, b, a);
        }

        void GLRenderCommands::ClearColorBit()
        {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        VertexArray* GLRenderCommands::CreateVertexArray()
        {
            return new GLVertexArray();
        }

        VertexBuffer* GLRenderCommands::CreateVertexBuffer()
        {
            return new GLVertexBuffer();
        }

        void GLRenderCommands::DrawArray(unsigned int count)
        {
            glDrawArrays(GL_TRIANGLES, 0, count);
        }

        Shader* GLRenderCommands::CreateShader(const char* vertexShaderSource, const char* fragmentShaderSource)
        {
            return new GLShader(vertexShaderSource, fragmentShaderSource);
        }
    }
}