#pragma once
#include "VertexBufferLayout.h"
#include "RenderProperties.h"

namespace ThunderEngine {
	namespace Graphics {
		class VertexBuffer {
		public:
			virtual void Bind() = 0;
			virtual void Delete() = 0;
			virtual void SetBufferData(const int size, const void* data, const BufferUsage usage) = 0;
			virtual void SetLayout(const VertexBufferLayout& layout) = 0;
			virtual void* GetPointer() = 0;
			virtual void ReleasePointer() = 0;
		public:
			virtual const VertexBufferLayout& GetLayout() const = 0;
		};
	}
}