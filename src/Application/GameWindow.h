#pragma once
#include <GLFW/glfw3.h>

namespace ThunderEngine {
	namespace Application {
		class GameWindow
		{
		private:
			static bool s_IsInitialized;
			static void InitializeLibrary();
			static void Terminate();
		private:
			GLFWwindow* m_Window;
			int m_Width;
			int m_Height;
			char* m_Title;
		public:
			GameWindow();
			~GameWindow();
			bool CreateWindow(int width, int height, char* title, GLFWmonitor* monitor, GLFWwindow* share);
			void MakeContextCurrent();
			bool ShouldWindowClose();
			void SwapBuffers();
			void PollEvents();
			void SetWindowSize(int width, int height);
			void SetWindowTitle(char* title);
			char* GetWindowTitle();
			int GetWindowHeight();
			int GetWindowWidth();
			void CloseWindow();
		};
	}
}

