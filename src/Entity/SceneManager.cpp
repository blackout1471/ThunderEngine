#include <tepch.h>
#include "SceneManager.h"

namespace ThunderEngine {
	namespace Entity {
		
		// Todo: Find out how to handle scene deletion from memory
		std::shared_ptr<SceneManager> SceneManager::s_SceneManager = std::make_shared<SceneManager>();

		template<typename T>
		void SceneManager::ChangeScene()
		{
			m_CurrentScene = new T();
			m_CurrentScene->OnStart();
		}

	}
}