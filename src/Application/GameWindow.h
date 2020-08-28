#pragma once
#include <GLFW/glfw3.h>
#include <Events/Event.h>
#include <functional>

namespace ThunderEngine {
	namespace Application {

		/// <summary>
		/// The windows data block for parameters that involves the windows specifications
		/// </summary>
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

			/// <summary>
			/// Initialises the glfw library if it has not already been initialised
			/// </summary>
			static void InitializeLibrary();

			/// <summary>
			/// Terminates the glfw library only use
			/// if all the windows has been closed
			/// </summary>
			static void Terminate();
		private:
			GLFWwindow* m_Window;
			GameWindowSpecifications m_Specifications;
		public:
			GameWindow();
			~GameWindow();

			/// <summary>
			/// Creates the window for the current object
			/// </summary>
			/// <param name="specifications">The windows parameter</param>
			/// <param name="monitor">The monitor to use</param>
			/// <param name="share">window to share data between</param>
			/// <returns></returns>
			bool CreateGameWindow(const GameWindowSpecifications& specifications, GLFWmonitor* monitor, GLFWwindow* share);
			
			
			/// <summary>
			/// make the current window the current context
			/// </summary>
			void MakeContextCurrent();
			
			
			/// <summary>
			/// Returns whether the window should close
			/// </summary>
			/// <returns></returns>
			bool ShouldWindowClose();
			
			
			/// <summary>
			/// Swaps the buffers for the window
			/// </summary>
			void SwapBuffers();
			
			
			/// <summary>
			/// Retrieves all events for all windows
			/// </summary>
			void PollEvents();
			
			
			/// <summary>
			/// Sets a new window size
			/// </summary>
			/// <param name="width"></param>
			/// <param name="height"></param>
			void SetWindowSize(int width, int height);
			
			
			/// <summary>
			/// Sets a new title for the window
			/// </summary>
			/// <param name="title"></param>
			void SetWindowTitle(const char* title);
			
			
			/// <summary>
			/// Gets the current title
			/// </summary>
			/// <returns></returns>
			const char* GetTitle();
			
			
			/// <summary>
			/// Gets the current height of the window
			/// </summary>
			/// <returns></returns>
			const int GetHeight();
			
			
			/// <summary>
			/// Gets the current width of the window
			/// </summary>
			/// <returns></returns>
			const int GetWidth();
			
			
			/// <summary>
			/// Closes the current window
			/// </summary>
			void CloseWindow();
			
			
			/// <summary>
			/// Sets whether the window should use v sync
			/// </summary>
			/// <param name="enabled"></param>
			void SetVSync(const bool enabled);
			
			
			/// <summary>
			/// Sets the event handler for the window
			/// </summary>
			/// <param name="eventHandler"></param>
			void SetEventHandler(const std::function<void(Events::Event&)>& eventHandler);
		private:
			
			
			/// <summary>
			/// Sets the events for the window
			/// </summary>
			void SetEvents();
		};
	}
}