#pragma once
#include "Graphics/VertexBuffer.h"

namespace ThunderEngine {
	namespace OpenGl {

		class GLVertexBuffer : public Graphics::VertexBuffer
		{
		private:
			unsigned int m_Id;
			Graphics::VertexBufferLayout m_BufferLayout;
		public:

		public:
			/// <summary>
			/// Creates a vertex buffer
			/// </summary>
			GLVertexBuffer();

			/// <summary>
			/// Binds the current vertex buffer
			/// </summary>
			virtual void Bind() override;

			/// <summary>
			/// Deletes the current vertex buffer from gpu
			/// </summary>
			virtual void Delete() override;

			/// <summary>
			/// Sets the data for the vertex buffer
			/// </summary>
			/// <param name="size">The size of the data in bytes</param>
			/// <param name="data">The data to be used</param>
			/// <param name="usage">How the buffer should respond</param>
			void SetBufferData(const int size, const void* data, const Graphics::BufferUsage usage) override;

			/// <summary>
			/// Set the layout for the vertex buffer
			/// </summary>
			/// <param name="layout"></param>
			virtual void SetLayout(const Graphics::VertexBufferLayout& layout) override;

			/// <summary>
			/// Gets the pointer to the buffer
			/// </summary>
			/// <returns></returns>
			virtual void* GetPointer() override;

			/// <summary>
			/// Releases the pointer for the buffer
			/// </summary>
			virtual void ReleasePointer() override;

		public:

			/// <summary>
			/// Returns the vertex buffer layout for the current vertex buffer
			/// </summary>
			/// <returns></returns>
			inline virtual const Graphics::VertexBufferLayout& GetLayout() const override
			{
				return m_BufferLayout;
			}

		public:
			/// <summary>
			/// Sets the attribute pointer in the shader for the vertex buffer
			/// </summary>
			/// <param name="index">location in the shader</param>
			/// <param name="size">the size of the data</param>
			/// <param name="normalised">Data normalised</param>
			/// <param name="verticeSize">how much an vertice fills</param>
			/// <param name="pointer"></param>
			void SetAttribPointer(const int index, const int size, const bool normalised, const int verticeSize, const void* pointer);
			
			/// <summary>
			/// Enable the location in the shader
			/// </summary>
			/// <param name="index"></param>
			void EnableAttribPointer(const int index);
		};
	}
}