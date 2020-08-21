#pragma once
#include <glm/glm.hpp>

namespace ThunderEngine {
	namespace Graphics {

		struct Vertex2D
		{
			glm::vec3 Vertice;
			glm::vec4 Color;
			glm::vec2 TextureCoordinates;
			float TextureId;
		};

		struct Vertex3D
		{
			glm::vec3 Vertice;
			glm::vec3 Normal;
			glm::vec2 TextureCoordination;
		};
	}
}