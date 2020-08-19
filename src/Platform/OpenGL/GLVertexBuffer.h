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
			GLVertexBuffer();

			virtual void Bind() override;
			virtual void Delete() override;
			void SetBufferData(const int size, const void* data, const Graphics::BufferUsage usage) override;
			virtual void SetLayout(const Graphics::VertexBufferLayout& layout) override;
			virtual void* GetPointer() override;
			virtual void ReleasePointer() override;

		public:
			inline virtual const Graphics::VertexBufferLayout& GetLayout() const override
			{
				return m_BufferLayout;
			}

		public:
			void SetAttribPointer(const int index, const int size, const bool normalised, const int verticeSize, const void* pointer);
			void EnableAttribPointer(const int index);

		};
	}
}