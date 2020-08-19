#include "tepch.h"
#include "Platform/OpenGL/GLRenderCommands.h"
#include <glad/glad.h>
#include "GLVertexBuffer.h"

namespace ThunderEngine {
	namespace OpenGl {
		GLVertexBuffer::GLVertexBuffer() : m_Id(0)
		{
			glGenBuffers(1, &m_Id);
		}

		void GLVertexBuffer::Bind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}

		void GLVertexBuffer::Delete()
		{
			glDeleteBuffers(1, &m_Id);
		}

		void GLVertexBuffer::SetBufferData(const int size, const void* data, const Graphics::BufferUsage usage)
		{
			glBufferData(GL_ARRAY_BUFFER, size, data, OpenGl::GLRenderCommands::PropertyToOpengl(usage));
		}

		void GLVertexBuffer::SetAttribPointer(const int index, const int size, const bool normalised, const int verticeSize, const void* pointer)
		{
			glVertexAttribPointer(index, size, GL_FLOAT, normalised, verticeSize * sizeof(float), pointer);
		}

		void GLVertexBuffer::EnableAttribPointer(const int index)
		{
			glEnableVertexAttribArray(index);
		}
		void GLVertexBuffer::SetLayout(const Graphics::VertexBufferLayout& layout)
		{
			m_BufferLayout = layout;
		}

		void* GLVertexBuffer::GetPointer()
		{
			return glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void GLVertexBuffer::ReleasePointer()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
		}
	}
}