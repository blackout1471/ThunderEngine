#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"

namespace ThunderEngine {
	class RenderCommands {
	public:
		virtual bool Init() = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;
		virtual void ClearColorBit() = 0;
		virtual VertexArray* CreateVertexArray() = 0;
		virtual VertexBuffer* CreateVertexBuffer() = 0;
		virtual Shader* CreateShader(const char* vertexShaderSource, const char* fragmentShaderSource) = 0;
		virtual void DrawArray(unsigned int count) = 0;
	};
}