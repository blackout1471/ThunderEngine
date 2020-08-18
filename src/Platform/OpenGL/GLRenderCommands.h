#pragma once
#include "Graphics/RenderCommands.h"

namespace ThunderEngine {
	namespace OpenGl {
		class GLRenderCommands : public RenderCommands {
			
			// Inherited via RenderCommands
			virtual bool Init() override;
			virtual void ClearColor(float r, float g, float b, float a) override;
			virtual void ClearColorBit() override;

			// Inherited via RenderCommands
			virtual VertexArray* CreateVertexArray() override;
			virtual VertexBuffer* CreateVertexBuffer() override;
			virtual Shader* CreateShader(const char* vertexShaderSource, const char* fragmentShaderSource) override;

			// Inherited via RenderCommands
			virtual void DrawArray(unsigned int count) override;
		};
	}
}