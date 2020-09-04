#pragma once
#include "System.h"
#include <array>

namespace ThunderEngine {
	namespace System {
		class SystemManager {
		private:
			static std::shared_ptr<SystemManager> s_SystemManager;

		private:
			std::array<System*, 1> m_Systems;
		public:
			SystemManager();
			~SystemManager();
			
			void OnStart();
			void OnUpdate();
			void OnDraw();

		public:
			static void InitSystems();
			inline static std::shared_ptr<SystemManager>& GetSystems() { return s_SystemManager; }
		};
	}
}