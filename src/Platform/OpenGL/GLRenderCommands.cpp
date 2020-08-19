#include "tepch.h"
#include "GLRenderCommands.h"
#include "GLVertexArray.h"
#include "GLVertexBuffer.h"
#include "GLIndexBuffer.h"
#include "GLShader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Core.h>
#include <Utils/FileUtils.h>

namespace ThunderEngine {
    namespace OpenGl {

		GLRenderCommands::GLRenderCommands() {}

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

			TE_LOG_INFO("Opengl: [{0}]", (char*)glGetString(GL_VERSION), '@');
			TE_LOG_INFO("Glsl: [{0}]", (char*)glGetString(GL_SHADING_LANGUAGE_VERSION), '@');
			TE_LOG_INFO("Vendor: [{0}]", (char*)glGetString(GL_VENDOR), '@');
			TE_LOG_INFO("Renderer: [{0}]", (char*)glGetString(GL_RENDERER), '@');

#if TE_DEBUG
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(OpenGLMessageCallback, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

            return true;
        }

		void GLRenderCommands::SetViewport(int _width, int _height)
		{
			glViewport(0, 0, _width, _height);
		}

		void GLRenderCommands::ClearColor(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
		}

		void GLRenderCommands::SetBlend(bool _enable)
		{
			if (_enable)
			{
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			else
			{
				glDisable(GL_BLEND);
			}
		}

		Graphics::VertexArray* GLRenderCommands::CreateVertexArray()
		{
			return new GLVertexArray();
		}

		Graphics::VertexBuffer* GLRenderCommands::CreateVertexBuffer(const unsigned int size)
		{
			GLVertexBuffer* _p = new GLVertexBuffer();
			_p->Bind();
			_p->SetBufferData(size, NULL, Graphics::BufferUsage::Dynamic_Draw);
			return _p;
		}

		Graphics::VertexBuffer* GLRenderCommands::CreateVertexBuffer(const void* data)
		{
			GLVertexBuffer* _p = new GLVertexBuffer();
			_p->Bind();
			_p->SetBufferData(sizeof(data), data, Graphics::BufferUsage::Static_Draw);
			return _p;
		}

		Graphics::IndexBuffer* GLRenderCommands::CreateIndexBuffer(const unsigned int size)
		{
			return new GLIndexBuffer(size);
		}

		Graphics::Shader* GLRenderCommands::CreateShader(const std::string vertexPath, const std::string fragmentPath)
		{
			std::string vShaderText = Utils::FileUtils::ReadFileContent(vertexPath);
			std::string fShaderText = Utils::FileUtils::ReadFileContent(fragmentPath);

			return new GLShader(vShaderText.c_str(), fShaderText.c_str());
		}

		void GLRenderCommands::ClearColorBit()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		Graphics::Shader* GLRenderCommands::CreateShader(const char* vertexSource, const char* fragmentSource)
		{
			return new GLShader(vertexSource, fragmentSource);
		}
    }
}