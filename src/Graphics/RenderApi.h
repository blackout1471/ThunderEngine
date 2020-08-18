#pragma once
#include <memory>

#include "RenderCommands.h"
#include "Platform/OpenGL/GLRenderCommands.h"

namespace ThunderEngine {
	enum class RenderVendor {
		None,
		OpenGL,
		DirectX
	};
	
	class RenderApi {
	private:
		static std::shared_ptr<ThunderEngine::RenderCommands> s_RenderApi;

	public:
		inline static void CreateApi(RenderVendor vendor) {
			switch (vendor)
			{
			case ThunderEngine::RenderVendor::None:
				break;
			case ThunderEngine::RenderVendor::OpenGL:
				s_RenderApi = std::make_shared<ThunderEngine::OpenGl::GLRenderCommands>();
				break;
			case ThunderEngine::RenderVendor::DirectX:
				break;
			}
		}

		inline static std::shared_ptr<ThunderEngine::RenderCommands>& GetApi() { return s_RenderApi; }
	};
}