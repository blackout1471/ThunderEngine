#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Texture.h"
#include "Shader.h"

namespace ThunderEngine {
	namespace Graphics {
		class RenderCommands {
		public:
			virtual bool Init() = 0;
			virtual void SetViewport(int _width, int _height) = 0;
			virtual void ClearColor(float r, float g, float b, float a) = 0;
			virtual void ClearColorBit() = 0;
			virtual void SetBlend(bool _enable) = 0;

			virtual VertexArray* CreateVertexArray() = 0;
			virtual VertexBuffer* CreateVertexBuffer(const void* data) = 0;
			virtual VertexBuffer* CreateVertexBuffer(const unsigned int size) = 0;
			virtual IndexBuffer* CreateIndexBuffer(const unsigned int size) = 0;

			virtual Shader* CreateShader(const std::string vertexPath, const std::string fragmentPath) = 0;
			virtual Shader* CreateShader(const char* vertexSource, const char* fragmentSource) = 0;

			virtual Texture* CreateTexture(const void* data, const Graphics::TextureProperties& properties) = 0;
			virtual Texture* CreateTexture(const char* path) = 0;
		};
	}
}