#pragma once
#include <Graphics/Texture.h>

namespace ThunderEngine {
	namespace OpenGl {
		class GLTexture : public Graphics::Texture {
		public:
			GLTexture();
			// Inherited via Texture
			virtual void ActivateTexture(const unsigned int slot) override;
			virtual void SetData(const unsigned char* data, const unsigned int width, const unsigned int height) override;
			virtual void Bind() override;

		private:
			void SetFiltering();
		};
	}
}