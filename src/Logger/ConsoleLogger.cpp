#include "tepch.h"
#include "ConsoleLogger.h"

namespace ThunderEngine {
	namespace Logger {
		ConsoleLogger::ConsoleLogger() : m_ConsoleId(0), m_ConsoleHandle(0), m_InfoColor(2), m_WarningColor(6), m_ErrorColor(4)
		{

		}

		void ConsoleLogger::Open()
		{
			m_ConsoleId = GetCurrentConsoleId();

			if (!IsConsoleAttached())
				CreateConsole();

			m_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		}

		void ConsoleLogger::Close()
		{
			FreeConsole();
		}

		bool ConsoleLogger::IsConsoleAttached()
		{
			return (GetCurrentProcessId() == m_ConsoleId);
		}

		DWORD ConsoleLogger::GetCurrentConsoleId()
		{
			HWND consoleWnd = GetConsoleWindow();
			DWORD dwProcessId;
			GetWindowThreadProcessId(consoleWnd, &dwProcessId);

			return dwProcessId;
		}

		void ConsoleLogger::CreateConsole()
		{
			AllocConsole();
			m_ConsoleId = GetCurrentConsoleId();
		}

		void ConsoleLogger::WriteInfo(const char* message)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_InfoColor);
			std::cout << message << std::endl;
		}

		void ConsoleLogger::WriteWarning(const char* message)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_WarningColor);
			std::cout << message << std::endl;
		}

		void ConsoleLogger::WriteError(const char* message)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_ErrorColor);
			std::cout << message << std::endl;
		}

	}
}

