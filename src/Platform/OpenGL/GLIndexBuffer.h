#pragma once
#include <Graphics/IndexBuffer.h>

namespace ThunderEngine {
	namespace OpenGl {
		class GLIndexBuffer : public Graphics::IndexBuffer {
		public:
			GLIndexBuffer(const unsigned int size);
			GLIndexBuffer(unsigned int* const indicies);
		public:
			virtual void Bind() override;
			virtual void Delete() override;

		private:
			void SetIndicies(unsigned int* const indicies);
		private:
			unsigned int m_Id;
		};
	}
}