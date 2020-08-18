#include "tepch.h"
#include <glad/glad.h>
#include "GLVertexArray.h"

namespace ThunderEngine {
	namespace OpenGl {

		GLVertexArray::GLVertexArray()
		{
			glGenVertexArrays(1, &m_Id);
		}

		GLVertexArray::~GLVertexArray()
		{
		}

		void GLVertexArray::InsertAttributePointer(unsigned int index, unsigned int size, ShaderType type, bool normalised, unsigned int stride, void* ptr)
		{
			unsigned int v = ShaderTypeConverter::ConvertToOpenglType(type);
			glVertexAttribPointer(index, size, v, normalised, stride, ptr);
		}

		void GLVertexArray::BindBuffer()
		{
			glBindVertexArray(m_Id);
		}

		void GLVertexArray::EnablePointer(unsigned int location)
		{
			glEnableVertexAttribArray(location);
		}
	}
}