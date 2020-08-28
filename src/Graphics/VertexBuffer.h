#pragma once
#include "VertexBufferLayout.h"
#include "RenderProperties.h"

namespace ThunderEngine {
	namespace Graphics {
		class VertexBuffer {
		public:
			/// <summary>
			/// Binds the current vertex buffer
			/// </summary>
			virtual void Bind() = 0;

			/// <summary>
			/// Deletes the vertex buffer from gpu
			/// </summary>
			virtual void Delete() = 0;

			/// <summary>
			/// Sets the data for the vertexBuffer
			/// </summary>
			/// <param name="size">The size of the data</param>
			/// <param name="data">The pointer to the data</param>
			/// <param name="usage">How the buffer should be used</param>
			virtual void SetBufferData(const int size, const void* data, const BufferUsage usage) = 0;

			/// <summary>
			/// Sets the layout for the buffer
			/// </summary>
			/// <param name="layout"></param>
			virtual void SetLayout(const VertexBufferLayout& layout) = 0;

			/// <summary>
			/// Gets the pointer for the current vertex buffer
			/// </summary>
			/// <returns></returns>
			virtual void* GetPointer() = 0;

			/// <summary>
			/// Releases the buffer pointer
			/// </summary>
			virtual void ReleasePointer() = 0;
		public:
			/// <summary>
			/// Gets the layout for the vertex buffer
			/// </summary>
			/// <returns></returns>
			virtual const VertexBufferLayout& GetLayout() const = 0;
		};
	}
}