#pragma once

namespace ThunderEngine {
	namespace Graphics {
		
		/// <summary>
		/// The textures properties
		/// Used to define how the texture should look like
		/// </summary>
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

			/// <summary>
			/// Activates the texture for shaders
			/// </summary>
			/// <param name="slot"></param>
			virtual void ActivateTexture(const unsigned int slot) = 0;

			/// <summary>
			/// Sets the data for the texture
			/// </summary>
			/// <param name="data">pointer to the rgba/rgb data</param>
			/// <param name="properties">How the data should be handled</param>
			virtual void SetData(const unsigned char* data, const TextureProperties& properties) = 0;

			/// <summary>
			/// Sets the texture as the current texture being handled
			/// </summary>
			virtual void Bind() = 0;

			/// <summary>
			/// Gets the width of the texture
			/// </summary>
			/// <returns></returns>
			inline const unsigned int GetWidth() const { return m_Properties.Width; }

			/// <summary>
			/// Gets the height of the texture
			/// </summary>
			/// <returns></returns>
			inline const unsigned int GetHeight() const { return m_Properties.Height; }
		};
	}
}