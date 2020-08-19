#pragma once
#include "RenderProperties.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace ThunderEngine {
	namespace Graphics {
		class VertexArray {
		public:
			virtual void Bind() = 0;
			virtual void Delete() = 0;

			virtual void SetVertexBuffer(const VertexBuffer* vertexBuffer) = 0;
			virtual void SetIndexBuffer(IndexBuffer* const indexBuffer) = 0;


			virtual void DrawArrays(RenderPrimitives primitive, const unsigned int offset, const unsigned int count) = 0;
			virtual void DrawIndicies(const RenderPrimitives primitive, const unsigned int count) = 0;
		};
	}
}