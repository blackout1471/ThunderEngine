#pragma once
#include "System.h"
#include <Graphics/RenderApi.h>
#include <Graphics/Vertice.h>
#include <Entity/Components.h>
#include <Entity/Scene.h>

#include <map>

#define RENDERER2D_MAX_ENTITIES = 5000; // The max amount of entities in the renderer

namespace ThunderEngine {
	namespace System {
		class Renderer2D : public System
		{
		private:
			Graphics::VertexArray* m_Vao;
			Graphics::VertexBuffer* m_Vbo;
			Graphics::IndexBuffer* m_Ibo;
			Graphics::Shader* m_Shader;
			Graphics::Texture* m_FlatTexture;
			Graphics::Vertex2D* m_BufferPointer;

			Entity::Scene* m_CurrentScene;

			// TODO: Let resourcemanager manage textures
			std::map<std::string, Graphics::Texture*> m_Textures;

			int m_CurrentIndicieCount;
		public:
			Renderer2D();
			~Renderer2D();
		public:
			virtual void OnStart() override;
			virtual void OnUpdate() override;
			virtual void OnDraw() override;

		private:
			void StartSubmit();
			void EndSubmit();

			void SubmitQuadComponents(Component::QuadComponent& quadComp, Component::TransformComponent& transComp);
			void SubmitSpriteComponents(Component::SpriteComponent& spriteComp, Component::TransformComponent& transComp);

			void UploadCameraMatrix();
			void SetTexturesForShader();

			void DrawIndicies();

		};
	}
}