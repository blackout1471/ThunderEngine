#include "tepch.h"
#include "Entity.h"

namespace ThunderEngine {
	namespace Entity {
		Entity::Entity(entt::entity handle, Scene* scene) :
			m_EntityHandle(handle), m_Scene(scene)
		{
		}
	}
}