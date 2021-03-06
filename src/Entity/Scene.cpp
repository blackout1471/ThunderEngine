#include "tepch.h"
#include "Scene.h"

#include "Entity.h"
#include "Components.h"

namespace ThunderEngine {
	namespace Entity {

		Scene::Scene()
		{
		}


		Scene::~Scene()
		{
		}

		Entity Scene::CreateEntity() {
			Entity entity = { m_Registry.create(), this };
			entity.AddComponent<Component::TransformComponent>();
			auto& tag = entity.AddComponent<Component::TagComponent>();
			tag.Tag = "Entity";
			return entity;
		}

	}
}