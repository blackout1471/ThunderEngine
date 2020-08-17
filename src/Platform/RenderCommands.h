#pragma once

namespace ThunderEngine {
	class RenderCommands {
	public:
		virtual bool Init() = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;
		virtual void ClearColorBit() = 0;
	};
}