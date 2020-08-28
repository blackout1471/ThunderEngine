#pragma once
#include "RenderProperties.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace ThunderEngine {
	namespace Graphics {
		class VertexArray {
		public:
			/// <summary>
			/// Binds the current vertex array as the current
			/// </summary>
			virtual void Bind() = 0;

			/// <summary>
			/// Deletes the current vertex array
			/// </summary>
			virtual void Delete() = 0;

			/// <summary>
			/// Sets the target vertex buffer to use
			/// </summary>
			/// <param name="vertexBuffer"></param>
			virtual void SetVertexBuffer(const VertexBuffer* vertexBuffer) = 0;

			/// <summary>
			/// Sets the target index buffer to use
			/// </summary>
			/// <param name="indexBuffer"></param>
			virtual void SetIndexBuffer(IndexBuffer* const indexBuffer) = 0;

			/// <summary>
			/// Draws the data given to the vertex array from the vertex buffer and the index buffer
			/// </summary>
			/// <param name="primitive">What shape to use</param>
			/// <param name="offset">The offset in the vertexBuffer</param>
			/// <param name="count">The amount of vertices to draw</param>
			virtual void DrawArrays(RenderPrimitives primitive, const unsigned int offset, const unsigned int count) = 0;

			/// <summary>
			/// Draws the data from the index buffer
			/// </summary>
			/// <param name="primitive">The shape to use</param>
			/// <param name="count">How many indicies to draw</param>
			virtual void DrawIndicies(const RenderPrimitives primitive, const unsigned int count) = 0;
		};
	}
}