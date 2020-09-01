#pragma once
#include <entt.hpp>
#include "Scene.h"

namespace ThunderEngine {
	namespace Entity {
		class Entity
		{
		private:
			entt::entity m_EntityHandle{ entt::null };
			Scene* m_Scene;
		public:
			Entity() = default;
			Entity(entt::entity handle, Scene* scene);

			template<typename T>
			bool HasComponent() 
			{
				return m_Scene->m_Registry.has<T>(m_EntityHandle);
			}

			template<typename T, typename... Args>
			T& AddComponent(Args&&... args) 
			{
				TE_ASSERT(!HasComponent<T>(), "Entity already has component", {});
				return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
			}

			template<typename T>
			T& GetComponent() 
			{
				TE_ASSERT(HasComponent<T>(), "Entity does not have component", {});
				return m_Scene->m_Registry.get<T>(m_EntityHandle);
			}

			template<typename T>
			void RemoveComponent() 
			{
				TE_ASSERT(HasComponent<T>(), "Entity does not have component", {});
				m_Scene->m_Registry.remove<T>(m_EntityHandle);
			}
		};
	}
}