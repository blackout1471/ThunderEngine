#pragma once
#include "../RenderCommands.h"

namespace ThunderEngine {
	namespace OpenGl {
		class GLRenderCommands : public RenderCommands {
			
			// Inherited via RenderCommands
			virtual bool Init() override;
			virtual void ClearColor(float r, float g, float b, float a) override;
			virtual void ClearColorBit() override;
		};
	}
}