#pragma once
#include <GLFW/glfw3.h>
#include "KeyCode.h"
#include "MouseButton.h"
#include <glm/glm.hpp>
namespace ThunderEngine {
	namespace Application {
		class Input
		{
		public:
			static glm::vec2 GetMousePos();
			static bool GetMouseDown(MouseButton mouseBtn);
			static bool GetMouseUp(MouseButton mouseBtn);
			static bool GetKeyDown(KeyCode keyCode);
			static bool GetKeyUp(KeyCode keyCode);
		public:
			GLFWkeyfun SetKeyCallBack(GLFWkeyfun callback);
		};

	}
}
