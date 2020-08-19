#include "tepch.h"
#include "ConsoleLogger.h"
#include <sstream>

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

		/// <summary>
		/// Replaces string with another, str is the string that is searched
		/// Returns false if it coudnt find the string to replace
		/// </summary>
		/// <returns></returns>
		bool ConsoleLogger::Replace(std::string& str, const std::string& toReplace, const std::string& replaceWith)
		{
			// Find position of the string
			size_t start_pos = str.find(toReplace);

			// Check if it found the string
			if (start_pos == std::string::npos)
				return false;
			str.replace(start_pos, toReplace.length(), replaceWith);
			return true;
		}

		/// <summary>
		/// Custom formatter replaces {0} with the first value that was splitted and so on
		/// </summary>
		/// <returns></returns>
		std::string ConsoleLogger::Format(std::string text, std::string args, const char splitter)
		{
			std::string indexString("{-1}");

			std::vector<std::string> splitString = Split(args, splitter);

			for (int i = 0; i < splitString.size(); i++)
			{
				Replace(indexString, std::to_string(i - 1), std::to_string(i));

				Replace(text, indexString, splitString[i]);
			}

			splitString.clear();
			return text;
		}

		std::vector<std::string> ConsoleLogger::Split(const std::string& s, char delim)
		{
			std::vector<std::string> result;
			std::stringstream ss(s);
			std::string item;

			while (std::getline(ss, item, delim)) {
				result.push_back(item);
			}

			return result;
		}
		

		void ConsoleLogger::Write(const std::string message)
		{
			std::cout << message << std::endl;
		}

		/// <summary>
		/// <para>string a = "doing"</para> 
		///	<para>string b = "fine"</para> 
		///	<para>Implementation:</para> 
		///	<para>Write("hi how are you {0} cuz i am {1}", a + "|" + b, '|');</para> 
		///	<para>Shows: hi how are you doing cuz i am fine</para> 
		/// </summary>
		void ConsoleLogger::Write(const std::string message, std::string args, const char splitter)
		{
			Write(Format(message, args, splitter));
		}


		void ConsoleLogger::WriteInfo(const std::string message)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_InfoColor);
			std::cout << message << std::endl;
		}

		void ConsoleLogger::WriteWarning(const std::string message)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_WarningColor);
			std::cout << message << std::endl;
		}

		void ConsoleLogger::WriteError(const std::string message)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_ErrorColor);
			std::cout << message << std::endl;
		}

	}
}

