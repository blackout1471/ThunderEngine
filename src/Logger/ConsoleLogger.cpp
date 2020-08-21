#include "tepch.h"
#include "ConsoleLogger.h"
#include <sstream>
#include <typeinfo>

namespace ThunderEngine {
	namespace Logger {
		ConsoleLogger::ConsoleLogger() : m_ConsoleId(0), m_ConsoleHandle(0), m_InfoColor(2), m_WarningColor(6), m_ErrorColor(4)
		{
			ConsoleLogger::Open();
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
			std::string indexString("{}");

			std::vector<std::string> splitString = Split(args, splitter);

			for (int i = 0; i < splitString.size(); i++)
			{
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


		void ConsoleLogger::Write(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec)
		{
			std::string tmp = "";
			for (size_t i = 0; i < vec.size(); i++)
			{
				size_t indexInVariant = vec[i].index();
			
				switch (indexInVariant)
				{
				case 0:
					tmp += std::get<std::string>(vec[i]);
					break;
				case 1:
					tmp += std::to_string(std::get<int>(vec[i]));
					break;
				case 2:
					tmp += std::to_string(std::get<float>(vec[i]));
					break;
				case 3:
					tmp += std::to_string(std::get<unsigned int>(vec[i]));
					break;

				default:
					tmp += "Error in ConsoleLogger Write method";
					break;
				}
				
				tmp += "|";
			}
			Write(message, tmp, '|');
		}

		/// <summary>
		///	<para>Implementation:</para> 
		///	<para>Write("{} are you doing with size of {}", { "how", 1, "float", 2.5f, "ge", "hello", 3.5f });</para> 
		///	<para>How are you doing with size of 1</para> 
		/// </summary>
		void ConsoleLogger::Write(const std::string message, std::string args, const char splitter)
		{
			Write(Format(message, args, splitter));
		}


		void ConsoleLogger::WriteInfo(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_InfoColor);
			ConsoleLogger::Write(message, vec);
		}

		void ConsoleLogger::WriteWarning(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_WarningColor);
			ConsoleLogger::Write(message, vec);
		}

		void ConsoleLogger::WriteError(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec)
		{
			SetConsoleTextAttribute(m_ConsoleHandle, m_ErrorColor);
			ConsoleLogger::Write(message, vec);
		}

	}
}

