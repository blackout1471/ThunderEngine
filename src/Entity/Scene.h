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

			// TEST DATA
			Graphics::VertexArray* m_Vao;
			Graphics::VertexBuffer* m_Vbo;
			Graphics::IndexBuffer* m_Ibo;
			Graphics::Shader* m_Shader;
			Graphics::Texture* m_FlatTexture;

		public:
			Scene();
			~Scene();

			Entity CreateEntity();
			void OnUpdate(); // TODO:: think about making it protected

			friend class Entity;
		};
	}
}