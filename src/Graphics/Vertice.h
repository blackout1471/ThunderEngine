#pragma once
#include <glm/glm.hpp>

namespace ThunderEngine {
	namespace Graphics {

		/// <summary>
		/// Used to represent a vertex in the 2d renderer
		/// </summary>
		struct Vertex2D
		{
			glm::vec3 Vertice;
			glm::vec4 Color;
			glm::vec2 TextureCoordinates;
			float TextureId;
		};

		/// <summary>
		/// Used to represent a vertex in the 3d renderer
		/// </summary>
		struct Vertex3D
		{
			glm::vec3 Vertice;
			glm::vec3 Normal;
			glm::vec2 TextureCoordination;
		};
	}
}