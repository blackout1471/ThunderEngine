#pragma once
#include "Graphics/RenderCommands.h"

namespace ThunderEngine {
	namespace OpenGl {
		class GLRenderCommands : public Graphics::RenderCommands {
		public:
			GLRenderCommands();

			/// <summary>
			/// Initialises the renderer's parameters
			/// </summary>
			/// <returns></returns>
			virtual bool Init() override;

			/// <summary>
			/// Sets the render view port
			/// </summary>
			/// <param name="_width"></param>
			/// <param name="_height"></param>
			virtual void SetViewport(int _width, int _height) override;
			
			/// <summary>
			/// The color to clear all the data to on each frame
			/// </summary>
			/// <param name="r"></param>
			/// <param name="g"></param>
			/// <param name="b"></param>
			/// <param name="a"></param>
			virtual void ClearColor(float r, float g, float b, float a) override;
			
			/// <summary>
			/// Sets whether to blend for colors
			/// </summary>
			/// <param name="_enable"></param>
			virtual void SetBlend(bool _enable) override;

			/// <summary>
			/// Creates a vertex array for the current api
			/// </summary>
			/// <returns></returns>
			virtual Graphics::VertexArray* CreateVertexArray() override;
			
			/// <summary>
			/// Creates a vertex buffer for the current api
			/// </summary>
			/// <param name="data"></param>
			/// <returns></returns>
			virtual Graphics::VertexBuffer* CreateVertexBuffer(const void* data) override;
			
			/// <summary>
			/// Creates a vertex buffer for the current api
			/// </summary>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual Graphics::VertexBuffer* CreateVertexBuffer(const unsigned int size) override;
			
			/// <summary>
			/// Creates a index buffer for the current api
			/// </summary>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual Graphics::IndexBuffer* CreateIndexBuffer(const unsigned int size) override;

			/// <summary>
			/// Creates a shader from source for the current api
			/// </summary>
			/// <param name="vertexSource"></param>
			/// <param name="fragmentSource"></param>
			/// <returns></returns>
			virtual Graphics::Shader* CreateShader(const char* vertexShaderSource, const char* fragmentShaderSource) override;
			
			/// <summary>
			/// Creates a shader from a file for the current api
			/// </summary>
			/// <param name="vertexPath"></param>
			/// <param name="fragmentPath"></param>
			/// <returns></returns>
			virtual Graphics::Shader* CreateShader(const std::string vertexPath, const std::string fragmentPath) override;

			/// <summary>
			/// Creates a texture from source data for the current api
			/// </summary>
			/// <param name="data"></param>
			/// <param name="properties"></param>
			/// <returns></returns>
			virtual Graphics::Texture* CreateTexture(const void* data, const Graphics::TextureProperties& properties) override;
			
			/// <summary>
			/// Creates a texture from file for current api
			/// </summary>
			/// <param name="path"></param>
			/// <returns></returns>
			virtual Graphics::Texture* CreateTexture(const char* path) override;
			
		public:

			/// <summary>
			/// Transforms bufferusage to unsigned int that opengl can recognize
			/// </summary>
			/// <param name="usage"></param>
			/// <returns></returns>
			static inline const unsigned int PropertyToOpengl(const Graphics::BufferUsage usage)
			{
				switch (usage)
				{
				case Graphics::BufferUsage::Static_Draw:
					return 0x88E4;
					break;
				case Graphics::BufferUsage::Dynamic_Draw:
					return 0x88E8;
					break;
				}
			}

			/// <summary>
			/// Transforms renderprimitives to opengl parameter
			/// </summary>
			/// <param name="primitives"></param>
			/// <returns></returns>
			static inline const unsigned int PropertyToOpengl(const Graphics::RenderPrimitives primitives)
			{
				switch (primitives)
				{
				case Graphics::RenderPrimitives::Quads:
					return 0x0007;
					break;
				case Graphics::RenderPrimitives::Traingles_Strip:
					return 0x0005;
					break;
				case Graphics::RenderPrimitives::Triangles:
					return 0x0004;
					break;
				}
			}

			/// <summary>
			/// Transforms shader type to opengl parameters
			/// </summary>
			/// <param name="type"></param>
			/// <returns></returns>
			static inline const unsigned int PropertyToOpengl(const Graphics::ShaderType type)
			{
				switch (type)
				{
				case Graphics::ShaderType::Float:
					return 0x1406;
					break;
				case Graphics::ShaderType::Int:
					return 0x1404;
					break;
				}
			}

			/// <summary>
			/// Sets that the color bits has to be cleared every frame update
			/// </summary>
			virtual void ClearColorBit() override;
			
		};
	}
}