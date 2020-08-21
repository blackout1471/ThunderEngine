#include "tepch.h"
#include "GameWindow.h"

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

		GameWindow::GameWindow() : m_Specifications(800, 600, "Yes"), m_Window(nullptr) {
			InitializeLibrary();
		}

		bool GameWindow::CreateGameWindow(const GameWindowSpecifications& specifications, GLFWmonitor* monitor, GLFWwindow* share) {
			m_Specifications = specifications;

			m_Window = glfwCreateWindow(m_Specifications.width, m_Specifications.height, m_Specifications.title, monitor, share);
			if (!m_Window)
				return false;

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
			m_Specifications.width = width;
			m_Specifications.height = height;
		}

		void GameWindow::SetWindowTitle(const char* title)
		{
			glfwSetWindowTitle(m_Window, title);
			m_Specifications.title = title;
		}

		const char* GameWindow::GetWindowTitle()
		{
			return m_Specifications.title;
		}

		const int GameWindow::GetWindowHeight()
		{
			return m_Specifications.height;
		}

		const int GameWindow::GetWindowWidth()
		{
			return m_Specifications.width;
		}

		void GameWindow::CloseWindow()
		{
			glfwDestroyWindow(m_Window);
		}

		void GameWindow::Terminate()
		{
			glfwTerminate();
		}

		GameWindow::~GameWindow() {
		}
	}
}