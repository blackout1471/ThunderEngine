#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Texture.h"
#include "Shader.h"

namespace ThunderEngine {
	namespace Graphics {
		class RenderCommands {
		public:
			/// <summary>
			/// Initialises the renderer's parameters
			/// </summary>
			/// <returns></returns>
			virtual bool Init() = 0;

			/// <summary>
			/// Sets the render view port
			/// </summary>
			/// <param name="_width"></param>
			/// <param name="_height"></param>
			virtual void SetViewport(int _width, int _height) = 0;
			
			/// <summary>
			/// The color to clear all the data to on each frame
			/// </summary>
			/// <param name="r"></param>
			/// <param name="g"></param>
			/// <param name="b"></param>
			/// <param name="a"></param>
			virtual void ClearColor(float r, float g, float b, float a) = 0;
			
			/// <summary>
			/// Sets that the color bits has to be cleared every frame update
			/// </summary>
			virtual void ClearColorBit() = 0;

			/// <summary>
			/// Sets whether to blend for colors
			/// </summary>
			/// <param name="_enable"></param>
			virtual void SetBlend(bool _enable) = 0;

			/// <summary>
			/// Creates a vertex array for the current api
			/// </summary>
			/// <returns></returns>
			virtual VertexArray* CreateVertexArray() = 0;

			/// <summary>
			/// Creates a vertex buffer for the current api
			/// </summary>
			/// <param name="data">The data that will be attached</param>
			/// <returns></returns>
			virtual VertexBuffer* CreateVertexBuffer(const void* data) = 0;
			
			/// <summary>
			/// Creates a vertex buffer for the current api
			/// </summary>
			/// <param name="size">The size of the data in bytes</param>
			/// <returns></returns>
			virtual VertexBuffer* CreateVertexBuffer(const unsigned int size) = 0;
			
			/// <summary>
			/// Creates a index buffer for the current api
			/// </summary>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual IndexBuffer* CreateIndexBuffer(const unsigned int size) = 0;

			/// <summary>
			/// Creates a shader from a file for the current api
			/// </summary>
			/// <param name="vertexPath"></param>
			/// <param name="fragmentPath"></param>
			/// <returns></returns>
			virtual Shader* CreateShader(const std::string vertexPath, const std::string fragmentPath) = 0;
			
			/// <summary>
			/// Creates a shader from source for the current api
			/// </summary>
			/// <param name="vertexSource"></param>
			/// <param name="fragmentSource"></param>
			/// <returns></returns>
			virtual Shader* CreateShader(const char* vertexSource, const char* fragmentSource) = 0;

			/// <summary>
			/// Creates a texture from source data for the current api
			/// </summary>
			/// <param name="data"></param>
			/// <param name="properties"></param>
			/// <returns></returns>
			virtual Texture* CreateTexture(const void* data, const Graphics::TextureProperties& properties) = 0;
			
			/// <summary>
			/// Creates a texture from file for current api
			/// </summary>
			/// <param name="path"></param>
			/// <returns></returns>
			virtual Texture* CreateTexture(const char* path) = 0;
		};
	}
}