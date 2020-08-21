#pragma once
#include "Texture.h"

namespace ThunderEngine {
	namespace Graphics {
		class FrameBuffer {
		protected:
			unsigned int m_Id;
			FrameBufferSpecifications m_Specifications;
		protected:
			FrameBuffer() {};
		public:
			virtual ~FrameBuffer() = 0;
		public:
			virtual void Bind() = 0;
			virtual void Unbind() = 0;
			virtual void Resize(const unsigned int width, const unsigned int height) = 0;
		public:
			const FrameBufferSpecifications& GetSpecifications() const { return m_Specifications; }
		};

		struct FrameBufferSpecifications {
			unsigned int width;
			unsigned int height;
			unsigned int samples;
		};
	}
}