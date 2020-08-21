#pragma once

namespace ThunderEngine {
	namespace Graphics {
		struct TextureProperties {
			TextureProperties(const unsigned int width, const unsigned int height, const char channels) {
				Width = width;
				Height = height;
				Channels = channels;
			}

			unsigned int Width;
			unsigned int Height;
			unsigned char Channels;
		};

		class Texture {
		protected:
			unsigned int m_Id;
			TextureProperties m_Properties;
			Texture() : m_Properties(0, 0, 0), m_Id() {}
		public:
			virtual void ActivateTexture(const unsigned int slot) = 0;
			virtual void SetData(const unsigned char* data, const TextureProperties& properties) = 0;
			virtual void Bind() = 0;

			inline const unsigned int GetWidth() const { return m_Properties.Width; }
			inline const unsigned int GetHeight() const { return m_Properties.Height; }
		};
	}
}