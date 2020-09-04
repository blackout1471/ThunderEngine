#include <tepch.h>
#include "SceneManager.h"

namespace ThunderEngine {
	namespace Entity {
		
		Scene* SceneManager::s_CurrentScene = nullptr;

		void SceneManager::SetScene(Scene* scene)
		{
			SceneManager::s_CurrentScene = scene;
			SceneManager::s_CurrentScene->OnStart();
		}

	}
}