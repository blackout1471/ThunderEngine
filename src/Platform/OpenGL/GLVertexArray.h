#pragma once
#include "Graphics/VertexArray.h"

namespace ThunderEngine {
	namespace OpenGl {
		class GLVertexArray : public VertexArray
		{
		private:
			unsigned int m_Id;
		public:
			GLVertexArray();
			~GLVertexArray();

			// Inherited via VertexArray
			virtual void InsertAttributePointer(unsigned int index, unsigned int size, ShaderType type, bool normalised, unsigned int stride, void* ptr) override;
			virtual void EnablePointer(unsigned int location) override;
			virtual void BindBuffer() override;
		};
	}
}

