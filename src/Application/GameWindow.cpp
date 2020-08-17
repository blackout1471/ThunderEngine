#include "tepch.h"
#include "GameWindow.h"

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
	GameWindow::GameWindow() {
		InitializeLibrary();
	}
	bool GameWindow::CreateWindow(int width, int height, char* title, GLFWmonitor* monitor, GLFWwindow* share) {
		m_Window = glfwCreateWindow(width, height, title, monitor, share);
		m_Width = width;
		m_Height = height;
		m_Title = title;
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
		m_Width = width;
		m_Height = height;
	}
	void GameWindow::SetWindowTitle(char* title)
	{
		glfwSetWindowTitle(m_Window, title);
		m_Title = title;
	}
	GameWindow::~GameWindow() {
		delete m_Window;
		delete m_Title;
	}
}