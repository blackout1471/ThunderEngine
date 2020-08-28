#pragma once
#include "Graphics/VertexArray.h"


namespace ThunderEngine {
	namespace OpenGl {
		class GLVertexArray : public Graphics::VertexArray
		{
		private:
			unsigned int m_Id;
		public:
			GLVertexArray();

			/// <summary>
			/// Binds the current vertex array
			/// </summary>
			virtual void Bind() override;

			/// <summary>
			/// Deletes the current vertex array
			/// </summary>
			virtual void Delete() override;

			/// <summary>
			/// Sets the current vertex buffer for the vertex array to use
			/// </summary>
			/// <param name="vertexBuffer"></param>
			virtual void SetVertexBuffer(const Graphics::VertexBuffer* vertexBuffer) override;

			/// <summary>
			/// Sets the current index buffer for the vertex array to use
			/// </summary>
			/// <param name="indexBuffer"></param>
			virtual void SetIndexBuffer(Graphics::IndexBuffer* const indexBuffer) override;

			/// <summary>
			/// Draw the data given from the vertex buffer
			/// </summary>
			/// <param name="primitive">What shape to use</param>
			/// <param name="offset">The offset, or position to start from</param>
			/// <param name="count">How many vertices to draw</param>
			virtual void DrawArrays(Graphics::RenderPrimitives primitive, const unsigned int offset, const unsigned int count) override;

			/// <summary>
			/// Draws the data from the index buffer
			/// </summary>
			/// <param name="primitive">What shape to use</param>
			/// <param name="count">How many indicies to draw</param>
			virtual void DrawIndicies(const Graphics::RenderPrimitives primitive, const unsigned int count) override;

		};
	}
}

