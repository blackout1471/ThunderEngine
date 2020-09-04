#pragma once

#include "Scene.h"

namespace ThunderEngine {
	namespace Entity {

		// TODO: See into deleting the scene afterwards
		class SceneManager {
		private:
			static std::shared_ptr<SceneManager> s_SceneManager;
		public:
			inline static std::shared_ptr<SceneManager>& GetScenes() { return s_SceneManager; }

		private:
			Scene* m_CurrentScene;

		public:
			template<typename T>
			void ChangeScene();

			inline Scene* GetCurrentScene() { return m_CurrentScene; }
		};
	}
}