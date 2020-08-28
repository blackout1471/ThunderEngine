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

			/// <summary>
			/// Gets the current position of the mouse
			/// </summary>
			/// <returns></returns>
			static glm::vec2 GetMousePos();

			/// <summary>
			/// Returns whether the given mouse button is pressed
			/// </summary>
			/// <param name="mouseBtn"></param>
			/// <returns></returns>
			static bool GetMouseDown(MouseButton mouseBtn);

			/// <summary>
			/// Returns whether the given mouse button is up
			/// </summary>
			/// <param name="mouseBtn"></param>
			/// <returns></returns>
			static bool GetMouseUp(MouseButton mouseBtn);

			/// <summary>
			/// returns whether the given key is down
			/// </summary>
			/// <param name="keyCode"></param>
			/// <returns></returns>
			static bool GetKeyDown(KeyCode keyCode);

			/// <summary>
			/// Returns whether the given key is up
			/// </summary>
			/// <param name="keyCode"></param>
			/// <returns></returns>
			static bool GetKeyUp(KeyCode keyCode);
		};

	}
}
