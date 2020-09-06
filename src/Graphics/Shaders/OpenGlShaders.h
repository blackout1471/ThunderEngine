#pragma once

namespace ThunderEngine {
	namespace Shaders {
		class OpenGlShaders {
		public:
			static inline const char* Shader2DVertex =
				"#version 330 core\n"

				"layout(location = 0) in vec3 aPos;\n"
				"layout(location = 1) in vec4 aColor;\n"
				"layout(location = 2) in vec2 aUv;\n"
				"layout(location = 3) in float aTextureId;\n"

				"out vec4 outColor;\n"
				"out vec2 outUv;\n"
				"out float outTextureId;\n"

				"uniform mat4 orthoView;\n"

				"void main()\n"
				"{\n"
				"	gl_Position = orthoView * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"	outColor = aColor;\n"
				"	outUv = aUv;\n"
				"	outTextureId = aTextureId;\n"
				"};";

			static inline const char* Shader2DFragment =
				"#version 330 core\n"
				"in vec4 outColor;\n"
				"in vec2 outUv;\n"
				"in float outTextureId;\n"

				"out vec4 FragColor;\n"

				"uniform sampler2D[32] textures;\n"

				"void main()\n"
				"{\n"
				"	int tid = int(outTextureId);\n"
				"	FragColor = texture(textures[tid], outUv) * outColor;\n"
				"}\n";
		};
	}
}