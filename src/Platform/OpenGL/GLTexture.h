#pragma once
#include <Graphics/Texture.h>

namespace ThunderEngine {
	namespace OpenGl {
		class GLTexture : public Graphics::Texture {
		public:
			GLTexture();
			
			/// <summary>
			/// Activates the texture in the shader slot
			/// </summary>
			/// <param name="slot"></param>
			virtual void ActivateTexture(const unsigned int slot) override;

			/// <summary>
			/// Sets the data for the texture
			/// </summary>
			/// <param name="data">Pointer to the image data</param>
			/// <param name="properties">How the texture's properties are handled</param>
			virtual void SetData(const unsigned char* data, const Graphics::TextureProperties& properties) override;

			/// <summary>
			/// Bind the texture as the current that Opengl should handle
			/// </summary>
			virtual void Bind() override;

		private:

			// TODO: More filtering options globally
			/// <summary>
			/// Sets filtering for image
			/// </summary>
			void SetFiltering();
		};
	}
}