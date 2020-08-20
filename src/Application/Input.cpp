#include "tepch.h"
#include "Input.h"
namespace ThunderEngine {
	namespace Application {
		GLFWkeyfun Input::SetKeyCallBack(GLFWkeyfun callback)
		{
			return glfwSetKeyCallback(glfwGetCurrentContext(), callback);
		}
	}
}