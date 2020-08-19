#pragma once
#include <GLFW/glfw3.h>

namespace ThunderEngine {
	class Time {
	private:
		static float s_deltaTime;
	public:
		inline static float GetDeltaTime() { return s_deltaTime; }
		inline static float GetFPS() { return 1.0f / s_deltaTime; }
		inline static float GetCurrentProcessTime() { return (float)glfwGetTime(); }
	public:
		inline static void SetDeltaTime(const float val) { s_deltaTime = val; }
	};
}