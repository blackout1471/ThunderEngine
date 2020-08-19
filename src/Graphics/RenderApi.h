#pragma once
#include <memory>

#include "RenderCommands.h"
#include "Platform/OpenGL/GLRenderCommands.h"

namespace ThunderEngine {
	namespace Graphics {
		enum class RenderVendor {
			None,
			OpenGL,
			DirectX
		};

		class RenderApi {
		private:
			static std::shared_ptr<RenderCommands> s_RenderApi;

		public:
			inline static void CreateApi(RenderVendor vendor) {
				switch (vendor)
				{
				case RenderVendor::None:
					break;
				case RenderVendor::OpenGL:
					RenderApi::s_RenderApi = std::make_shared<OpenGl::GLRenderCommands>();
					break;
				case RenderVendor::DirectX:
					break;
				}
			}

			inline static std::shared_ptr<RenderCommands>& GetApi() { return s_RenderApi; }
		};
	}
}