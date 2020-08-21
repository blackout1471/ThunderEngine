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
			GameWindowSpecifications m_Specifications;
		public:
			GameWindow();
			~GameWindow();
			bool CreateGameWindow(const GameWindowSpecifications& specifications, GLFWmonitor* monitor, GLFWwindow* share);
			void MakeContextCurrent();
			bool ShouldWindowClose();
			void SwapBuffers();
			void PollEvents();
			void SetWindowSize(int width, int height);
			void SetWindowTitle(const char* title);
			const char* GetWindowTitle();
			const int GetWindowHeight();
			const int GetWindowWidth();
			void CloseWindow();
		};

		struct GameWindowSpecifications {
			GameWindowSpecifications(unsigned int width, unsigned int height, const char* title) {
				this->width = width;
				this->height = height;
				this->title = title;
			}

			unsigned int width;
			unsigned int height;
			const char* title;
		};
	}
}

