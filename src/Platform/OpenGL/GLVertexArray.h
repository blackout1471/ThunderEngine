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

			virtual void Bind() override;

			virtual void Delete() override;

			virtual void SetVertexBuffer(const Graphics::VertexBuffer* vertexBuffer) override;

			virtual void SetIndexBuffer(Graphics::IndexBuffer* const indexBuffer) override;

			virtual void DrawArrays(Graphics::RenderPrimitives primitive, const unsigned int offset, const unsigned int count) override;

			virtual void DrawIndicies(const Graphics::RenderPrimitives primitive, const unsigned int count) override;

		};
	}
}

