#pragma once
#include <GLFW/glfw3.h>
namespace ThunderEngine {
	namespace Application {
		class Input
		{
		public:
			GLFWkeyfun SetKeyCallBack(GLFWkeyfun callback);
		};

	}
}
