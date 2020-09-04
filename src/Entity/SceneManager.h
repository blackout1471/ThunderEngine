#pragma once

#include "Scene.h"

namespace ThunderEngine {
	namespace Entity {

		// TODO: See into deleting the scene afterwards
		class SceneManager {
		private:
			static Scene* s_CurrentScene;

		public:
			static void SetScene(Scene* scene);

			inline static Scene* GetCurrentScene() { return s_CurrentScene; }
		};
	}
}