#include "tepch.h"
#include <glad/glad.h>
#include "GLTexture.h"

namespace ThunderEngine {
	namespace OpenGl {

		GLTexture::GLTexture()
		{
			glGenTextures(1, &m_Id);
		}

		void GLTexture::ActivateTexture(const unsigned int slot)
		{
			glActiveTexture(GL_TEXTURE0 + slot);
		}

		void GLTexture::SetData(const unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int channels)
		{
			unsigned int internalFormat;
			unsigned int dataFormat;

			switch (channels)
			{
			case 3:
				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
				break;
			default:
				internalFormat = GL_RGB8;
				dataFormat = GL_RGBA;
				break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
			SetFiltering();
		}

		void GLTexture::Bind()
		{
			glBindTexture(GL_TEXTURE_2D, m_Id);
		}

		void GLTexture::SetFiltering()
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		}
	}
}