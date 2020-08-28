#pragma once
#include <Graphics/IndexBuffer.h>

namespace ThunderEngine {
	namespace OpenGl {
		class GLIndexBuffer : public Graphics::IndexBuffer {
		public:
			/// <summary>
			/// Creates a index buffer and generates square indicie data
			/// </summary>
			/// <param name="size">The amount of indicies to have</param>
			GLIndexBuffer(const unsigned int size);

			/// <summary>
			/// Creates a index buffer from index data
			/// </summary>
			/// <param name="indicies"></param>
			GLIndexBuffer(unsigned int* const indicies);
		public:
			/// <summary>
			/// Binds the current index buffer
			/// </summary>
			virtual void Bind() override;

			/// <summary>
			/// Deletes the current index buffer from gpu
			/// </summary>
			virtual void Delete() override;
		private:
			/// <summary>
			/// Sets the indicie data for the current index buffer
			/// </summary>
			/// <param name="indicies">The pointer to the data</param>
			void SetIndicies(unsigned int* const indicies);
		private:
			unsigned int m_Id;
		};
	}
}