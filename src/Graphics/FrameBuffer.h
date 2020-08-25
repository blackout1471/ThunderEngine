#pragma once
#include "Texture.h"

namespace ThunderEngine {
	namespace Graphics {
		struct FrameBufferSpecifications {
			FrameBufferSpecifications(unsigned int width, unsigned int height, unsigned int samples)
			{
				Width = width;
				Height = height;
				Samples = samples;
			}

			unsigned int Width;
			unsigned int Height;
			unsigned int Samples;
		};

		class FrameBuffer {
		protected:
			unsigned int m_Id;
			FrameBufferSpecifications m_Specifications;
		protected:
			FrameBuffer() : m_Id(0), m_Specifications(800, 600, 1) {};
		public:
			virtual ~FrameBuffer() = 0;
		public:
			virtual void Bind() = 0;
			virtual void Unbind() = 0;
			virtual void Resize(const unsigned int width, const unsigned int height) = 0;
		public:
			const FrameBufferSpecifications& GetSpecifications() const { return m_Specifications; }
		};
	}
}