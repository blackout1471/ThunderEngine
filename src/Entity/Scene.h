#pragma once
#include <entt.hpp>

#include <Graphics/RenderApi.h>

namespace ThunderEngine {
	namespace Entity {

		class Entity;

		class Scene
		{
		private:
			entt::registry m_Registry;

		public:
			Scene();
			~Scene();

			Entity CreateEntity();
			virtual void OnStart() = 0;
			virtual void OnUpdate() = 0;

			entt::registry& GetRegistry() { return m_Registry; }

			friend class Entity;
		};
	}
}