#pragma once
#include "Graphics/VertexBuffer.h"

namespace ThunderEngine {
	namespace OpenGl {

		class GLVertexBuffer : public VertexBuffer
		{
		private:
			unsigned int m_Id;
		public:
			GLVertexBuffer();
			~GLVertexBuffer();

			// Inherited via VertexBuffer
			virtual void SetData(void* data, unsigned int size) override;
			virtual void BindBuffer() override;
		};
	}
}