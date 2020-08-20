#pragma once
#include "Graphics/RenderCommands.h"

namespace ThunderEngine {
	namespace OpenGl {
		class GLRenderCommands : public Graphics::RenderCommands {
		public:
			GLRenderCommands();

			virtual bool Init() override;
			virtual void SetViewport(int _width, int _height) override;
			virtual void ClearColor(float r, float g, float b, float a) override;
			virtual void SetBlend(bool _enable) override;

			virtual Graphics::VertexArray* CreateVertexArray() override;
			virtual Graphics::VertexBuffer* CreateVertexBuffer(const void* data) override;
			virtual Graphics::VertexBuffer* CreateVertexBuffer(const unsigned int size) override;
			virtual Graphics::IndexBuffer* CreateIndexBuffer(const unsigned int size) override;

			virtual Graphics::Shader* CreateShader(const char* vertexShaderSource, const char* fragmentShaderSource) override;
			virtual Graphics::Shader* CreateShader(const std::string vertexPath, const std::string fragmentPath) override;

			virtual Graphics::Texture* CreateTexture(const void* data, const unsigned int width, const unsigned int height) override;
			virtual Graphics::Texture* CreateTexture(const char* path) override;
			
		public:
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

			// Inherited via RenderCommands
			virtual void ClearColorBit() override;
			
		};
	}
}