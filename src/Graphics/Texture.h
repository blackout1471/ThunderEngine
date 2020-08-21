#pragma once

namespace ThunderEngine {
	namespace Graphics {
		class Texture {
		protected:
			unsigned int m_Id;
			unsigned int m_Width;
			unsigned int m_Height;
			unsigned char m_Channels;
		public:
			virtual void ActivateTexture(const unsigned int slot) = 0;
			virtual void SetData(const unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int channels) = 0;
			virtual void Bind() = 0;

			inline const unsigned int GetWidth() const { return m_Width; }
			inline const unsigned int GetHeight() const { return m_Height; }
		};
	}
}