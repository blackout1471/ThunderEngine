#pragma once

namespace ThunderEngine {
	namespace Shaders {
		class OpenGlShaders {
		public:
			static inline const char* Shader2DVertex =
				"#version 330 core\n"

				"layout(location = 0) in vec3 aPos;\n"
				"layout(location = 1) in vec4 aColor;\n"

				"out vec4 outColor;\n"

				"void main()\n"
				"{\n"
				"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"	outColor = aColor;\n"
				"};";

			static inline const char* Shader2DFragment =
				"#version 330 core\n"
				"in vec4 outColor;\n"

				"out vec4 FragColor;\n"

				"void main()\n"
				"{\n"
				"	FragColor = outColor;\n"
				"}\n";
		};
	}
}