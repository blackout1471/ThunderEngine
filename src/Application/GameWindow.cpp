#include "tepch.h"
#include "GameWindow.h"
#include <Events/KeyEvent.h>
#include <Events/MouseEvent.h>
#include <Events/WindowEvent.h>

namespace ThunderEngine {
	namespace Application {

		bool GameWindow::s_IsInitialized = false;

		void GameWindow::InitializeLibrary()
		{
			if (!s_IsInitialized)
			{
				glfwInit();
				GameWindow::s_IsInitialized = true;
			}
		}

		GameWindow::GameWindow() : m_Specifications(800, 600, "Thunder Engine", true), m_Window(nullptr) {
			InitializeLibrary();
		}

		bool GameWindow::CreateGameWindow(const GameWindowSpecifications& specifications, GLFWmonitor* monitor, GLFWwindow* share) {
			m_Specifications = specifications;

			m_Window = glfwCreateWindow(m_Specifications.Width, m_Specifications.Height, m_Specifications.Title, monitor, share);
			if (!m_Window)
				return false;

			SetVSync(specifications.VSync);

			glfwSetWindowUserPointer(m_Window, &m_Specifications);
			SetEvents();

			return true;
		}

		void GameWindow::MakeContextCurrent()
		{
			glfwMakeContextCurrent(m_Window);
		}

		bool GameWindow::ShouldWindowClose()
		{
			return glfwWindowShouldClose(m_Window);
		}


		void GameWindow::SwapBuffers()
		{
			glfwSwapBuffers(m_Window);
		}


		void GameWindow::PollEvents()
		{
			glfwPollEvents();
		}


		void GameWindow::SetWindowSize(int width, int height)
		{
			glfwSetWindowSize(m_Window, width, height);
			m_Specifications.Width = width;
			m_Specifications.Height = height;
		}


		void GameWindow::SetWindowTitle(const char* title)
		{
			glfwSetWindowTitle(m_Window, title);
			m_Specifications.Title = title;
		}

		const char* GameWindow::GetTitle()
		{
			return m_Specifications.Title;
		}

		const int GameWindow::GetHeight()
		{
			return m_Specifications.Height;
		}

		const int GameWindow::GetWidth()
		{
			return m_Specifications.Width;
		}

		void GameWindow::CloseWindow()
		{
			glfwDestroyWindow(m_Window);
		}

		void GameWindow::SetVSync(const bool enabled)
		{
			m_Specifications.VSync = enabled;

			if (m_Specifications.VSync)
				glfwSwapInterval(1);
			else
				glfwSwapInterval(0);
		}

		void GameWindow::SetEvents()
		{
			glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* wnd, int width, int height) {
				GameWindowSpecifications& data = *(GameWindowSpecifications*)glfwGetWindowUserPointer(wnd);
				data.Width = width;
				data.Height = height;
				Events::WindowResizeEvent event(width, height);

				data.EventCallBack(event);
			});

			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* wnd) {
				GameWindowSpecifications& data = *(GameWindowSpecifications*)glfwGetWindowUserPointer(wnd);

				Events::WindowCloseEvent event;
				data.EventCallBack(event);
			});

			glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* wnd, int focused) {
				GameWindowSpecifications& data = *(GameWindowSpecifications*)glfwGetWindowUserPointer(wnd);

				Events::WindowFocusEvent event((bool)focused);
				data.EventCallBack(event);
			});

			glfwSetKeyCallback(m_Window, [](GLFWwindow* wnd, int key, int scancode, int action, int mods) {
				GameWindowSpecifications& data = *(GameWindowSpecifications*)glfwGetWindowUserPointer(wnd);

				switch (action)
				{
					case 1: // press
					{
						Events::KeyPressedEvent event(static_cast<KeyCode>(key), scancode, mods);
						data.EventCallBack(event);
						break;
					}
					case 0: // Release
					{
						Events::KeyReleasedEvent event(static_cast<KeyCode>(key), scancode, mods);
						data.EventCallBack(event);
						break;
					}
					case 2: // Repeat;
					{
						Events::KeyRepeatEvent event(static_cast<KeyCode>(key), scancode, mods);
						data.EventCallBack(event);
						break;
					}
				}
			});

			glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* wnd, int button, int action, int mods) {
				GameWindowSpecifications& data = *(GameWindowSpecifications*)glfwGetWindowUserPointer(wnd);

				switch (action)
				{
					case 1: // press
					{
						Events::MousePressedEvent event(static_cast<MouseButton>(button), mods);
						data.EventCallBack(event);
						break;
					}
					case 0: // Release
					{
						Events::MouseReleasedEvent event(static_cast<MouseButton>(button), mods);
						data.EventCallBack(event);
						break;
					}
					case 2: // Repeat;
					{
						Events::MouseRepeatEvent event(static_cast<MouseButton>(button), mods);
						data.EventCallBack(event);
						break;
					}
				}
			});
		}


		void GameWindow::SetEventHandler(const std::function<void(Events::Event&)>& eventHandler)
		{
			m_Specifications.EventCallBack = eventHandler;
		}

		void GameWindow::Terminate()
		{
			glfwTerminate();
		}

		GameWindow::~GameWindow() {
			this->CloseWindow();
			delete m_Window;
		}
	}
}