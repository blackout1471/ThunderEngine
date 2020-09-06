#pragma once
#include <Graphics/Vertice.h>
#include <Graphics/OrthographicCamera.h>
#include "Transform.h"

namespace ThunderEngine {
	namespace Component {
		struct Test2DQuadComponent {
			Graphics::Vertex2D urc;
			Graphics::Vertex2D drc;
			Graphics::Vertex2D dlc;
			Graphics::Vertex2D ulc;

			Test2DQuadComponent(const float size, const glm::vec4 color) {
				urc = Graphics::Vertex2D();
				drc = Graphics::Vertex2D();
				dlc = Graphics::Vertex2D();
				ulc = Graphics::Vertex2D();

				urc.Vertice = glm::vec3(size, size, 0.f);
				drc.Vertice = glm::vec3(size, -size, 0.f);
				dlc.Vertice = glm::vec3(-size, -size, 0.f);
				ulc.Vertice = glm::vec3(-size, size, 0.f);

				urc.Color = color;
				drc.Color = color;
				dlc.Color = color;
				ulc.Color = color;

				urc.TextureCoordinates = glm::vec2(1.f, 0.f);
				drc.TextureCoordinates = glm::vec2(1.f, 1.f);
				dlc.TextureCoordinates = glm::vec2(0.f, 1.f);
				ulc.TextureCoordinates = glm::vec2(0.0f, 0.f);

				urc.TextureId = 0.f;
				drc.TextureId = 0.f;
				dlc.TextureId = 0.f;
				ulc.TextureId = 0.f;
			}
		};

		// TODO: Make constructor based position
		struct TransformComponent {

			Entity::Transform Transform = Entity::Transform();

			TransformComponent() = default;
			TransformComponent(const TransformComponent&) = default;
		};

		struct OrthographicCameraComponent {
			bool IsPrimary = true;
			Graphics::OrthographicCamera Camera = Graphics::OrthographicCamera();

			OrthographicCameraComponent() = default;
			OrthographicCameraComponent(const OrthographicCameraComponent&) = default;
		};

		struct TagComponent {
			std::string Tag;

			TagComponent() = default;
			TagComponent(const TagComponent&) = default;
			TagComponent(const std::string& tag) : Tag(tag) {};
		};
	}
}