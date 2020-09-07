#pragma once
#include <Graphics/Vertice.h>
#include <Graphics/OrthographicCamera.h>
#include "Transform.h"

namespace ThunderEngine {
	namespace Component {

		struct QuadComponent {
			float Width;
			float Height;
			glm::vec4 Color;

			QuadComponent() = default;
			QuadComponent(const QuadComponent&) = default;
			QuadComponent(float width, float height, glm::vec4 color) : Width(width), Height(height), Color(color) {}
			QuadComponent(float size, glm::vec4 color) : Width(size / 2), Height(size / 2), Color(color) {}
		};

		// TODO: Let resource manager handle the creation of the sprite, and pass the identifier to the spriterenderer
		struct SpriteComponent {
			std::string Path;
			float Width;
			float Height;
			glm::vec4 Color;

			SpriteComponent() = default;
			SpriteComponent(const SpriteComponent&) = default;
			SpriteComponent(const std::string& path, float width, float height, glm::vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f }) : Width(width), Height(height), Color(color), Path(path) {};
			SpriteComponent(const std::string& path, float size, glm::vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f }) : Width(size / 2), Height(size / 2), Color(color), Path(path) {};
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