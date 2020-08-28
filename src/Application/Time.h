#pragma once
#include <GLFW/glfw3.h>

namespace ThunderEngine {
	class Time {
	private:
		static float s_deltaTime;
	public:

		/// <summary>
		/// Returns the current delta time for the previous frame and the current
		/// </summary>
		/// <returns></returns>
		inline static float GetDeltaTime() { return s_deltaTime; }

		/// <summary>
		/// returns the delta time as fps -> Frames Per Seconds
		/// </summary>
		/// <returns></returns>
		inline static float GetFPS() { return 1.0f / s_deltaTime; }

		/// <summary>
		/// Gets the current process time with glfw
		/// </summary>
		/// <returns></returns>
		inline static float GetCurrentProcessTime() { return (float)glfwGetTime(); }
	public:

		/// <summary>
		/// Sets the delta time
		/// </summary>
		/// <param name="val"></param>
		inline static void SetDeltaTime(const float val) { s_deltaTime = val; }
	};
}