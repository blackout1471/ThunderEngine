#pragma once
#include <GLFW/glfw3.h>
#include <Events/Event.h>
#include <functional>

namespace ThunderEngine {
	namespace Application {
		struct GameWindowSpecifications {
			GameWindowSpecifications(unsigned int width, unsigned int height, const char* title, const bool vsync) {
				this->Width = width;
				this->Height = height;
				this->Title = title;
				this->VSync = vsync;
			}

			unsigned int Width;
			unsigned int Height;
			const char* Title;
			bool VSync;

			std::function<void(Events::Event&)> EventCallBack;
		};

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
			const char* GetTitle();
			const int GetHeight();
			const int GetWidth();
			void CloseWindow();
			void SetVSync(const bool enabled);
			void SetEventHandler(std::function<void(Events::Event&)> eventHandler);
		private:
			void SetEvents();
		};
	}
}