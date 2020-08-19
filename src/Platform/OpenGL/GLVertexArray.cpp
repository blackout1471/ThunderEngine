#include "tepch.h"
#include <glad/glad.h>
#include "Platform/OpenGL/GLRenderCommands.h"
#include "GLVertexArray.h"

namespace ThunderEngine {
	namespace OpenGl {

		GLVertexArray::GLVertexArray() : m_Id(0)
		{
			glGenVertexArrays(1, &m_Id);
		}

		void GLVertexArray::Bind()
		{
			glBindVertexArray(m_Id);
		}

		void GLVertexArray::Delete()
		{
			glDeleteVertexArrays(1, &m_Id);
		}

		void GLVertexArray::SetVertexBuffer(const Graphics::VertexBuffer* vertexBuffer)
		{
			const auto& layout = vertexBuffer->GetLayout();

			for (const auto& element : layout)
			{
				glVertexAttribPointer(element.Index, element.Size, OpenGl::GLRenderCommands::PropertyToOpengl(element.Type), element.Normalised, layout.GetStride(), element.DataPointer);
				glEnableVertexAttribArray(element.Index);
			}
		}

		void GLVertexArray::SetIndexBuffer(Graphics::IndexBuffer* const indexBuffer)
		{
			indexBuffer->Bind();
		}

		void GLVertexArray::DrawArrays(const Graphics::RenderPrimitives primitive, const unsigned int offset, const unsigned int count)
		{
			glDrawArrays(GLRenderCommands::PropertyToOpengl(primitive), offset, count);
		}

		void GLVertexArray::DrawIndicies(const Graphics::RenderPrimitives primitive, const unsigned int count)
		{
			glDrawElements(GLRenderCommands::PropertyToOpengl(primitive), count, GL_UNSIGNED_INT, NULL);
		}
	}
}