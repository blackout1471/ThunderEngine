#pragma once
#include "System.h"
#include <array>

namespace ThunderEngine {
	namespace System {

		// Todo: Make remove function
		class SystemManager {
		private:
			static std::shared_ptr<SystemManager> s_SystemManager;

		private:
			std::vector<System*> m_Systems;
		public:
			SystemManager();
			~SystemManager();
			
			void OnStart();
			void OnUpdate();
			void OnDraw();

			void AddSystem(System* system);
		public:
			static void InitSystems();
			inline static std::shared_ptr<SystemManager>& GetSystems() { return s_SystemManager; }
		};
	}
}