#pragma once
#include <memory>

#include "RenderCommands.h"
#include <Core/Core.h>
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
					TE_LOG_INFO("CPU context has been created", "", '@');
					break;
				case RenderVendor::OpenGL:
					RenderApi::s_RenderApi = std::make_shared<OpenGl::GLRenderCommands>();
					TE_LOG_INFO("Opengl context has been created", "", '@');
					break;
				case RenderVendor::DirectX:
					TE_LOG_INFO("DirectX context has been created", "", '@');
					break;
				}
			}

			inline static std::shared_ptr<RenderCommands>& GetApi() { return s_RenderApi; }
		};
	}
}