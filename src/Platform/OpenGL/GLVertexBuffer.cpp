#include "tepch.h"
#include "GLVertexBuffer.h"
#include <glad/glad.h>

namespace ThunderEngine {
	namespace OpenGl {
		GLVertexBuffer::GLVertexBuffer()
		{
			glGenBuffers(1, &m_Id);
		}

		GLVertexBuffer::~GLVertexBuffer()
		{
		}

		void GLVertexBuffer::SetData(void* data, unsigned int size)
		{
			glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		}

		void GLVertexBuffer::BindBuffer()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}
	}
}