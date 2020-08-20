#include "tepch.h"
#include "Input.h"
namespace ThunderEngine {
	namespace Application {
		glm::vec2 Input::GetMousePos()
		{
			double xpos, ypos;
			glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
			
			return glm::vec2(xpos, ypos);
		}
		bool Input::GetMouseDown(MouseButton mouseBtn)
		{
			int state = glfwGetMouseButton(glfwGetCurrentContext(), (int)mouseBtn);
			return (state == 1 || state == 2);
		}
		bool Input::GetMouseUp(MouseButton mouseBtn)
		{
			int state = glfwGetMouseButton(glfwGetCurrentContext(), (int)mouseBtn);

			return (state == 0);
		}
		bool Input::GetKeyDown(KeyCode keyCode)
		{
			int state = glfwGetKey(glfwGetCurrentContext(), (int)keyCode);

			return (state == 1 || state == 2);
		}

		bool Input::GetKeyUp(KeyCode keyCode)
		{
			int state = glfwGetKey(glfwGetCurrentContext(), (int)keyCode);

			return (state == 0);
		}
		GLFWkeyfun Input::SetKeyCallBack(GLFWkeyfun callback)
		{
			return glfwSetKeyCallback(glfwGetCurrentContext(), callback);
		}
	}
}