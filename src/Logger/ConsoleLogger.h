#pragma once
#include "Logger.h"
#include <iostream>
#include <Windows.h>
#include <variant>

namespace ThunderEngine {
	namespace Logger {
		class ConsoleLogger : public Logger
		{
		private:
			DWORD m_ConsoleId;
			HANDLE m_ConsoleHandle;

			byte m_InfoColor;
			byte m_ErrorColor;
			byte m_WarningColor;
		public:
			ConsoleLogger();

			/// <summary>
			/// Opens a console if a console is not already present
			/// </summary>
			virtual void Open() override;

			/// <summary>
			/// Closes the console if present
			/// </summary>
			virtual void Close() override;

			/// <summary>
			/// Writes info to the console
			/// </summary>
			/// <param name="message"></param>
			/// <param name="vec"></param>
			virtual void WriteInfo(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) override;
			
			/// <summary>
			/// Writes a warning to the console
			/// </summary>
			/// <param name="message"></param>
			/// <param name="vec"></param>
			virtual void WriteWarning(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) override;
			
			/// <summary>
			/// Writes a error to the console
			/// </summary>
			/// <param name="message"></param>
			/// <param name="vec"></param>
			virtual void WriteError(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) override;
		private:
			/// <summary>
			/// Checks whether a console is already present
			/// </summary>
			/// <returns></returns>
			bool IsConsoleAttached();

			/// <summary>
			/// Gets the current id of the console
			/// </summary>
			/// <returns></returns>
			DWORD GetCurrentConsoleId();

			/// <summary>
			/// Creates a console
			/// </summary>
			void CreateConsole();
			
			/// <summary>
			/// Replaces a string into the target
			/// </summary>
			/// <param name="str"></param>
			/// <param name="from"></param>
			/// <param name="to"></param>
			/// <returns></returns>
			bool Replace(std::string& str, const std::string& from, const std::string& to);

			/// <summary>
			/// formats the text given the splitter and the arguments
			/// </summary>
			/// <param name="text"></param>
			/// <param name="args"></param>
			/// <param name="splitter"></param>
			/// <returns></returns>
			std::string Format(std::string text, std::string args, const char splitter);

			/// <summary>
			/// splits a string with delimiters
			/// </summary>
			/// <param name="s"></param>
			/// <param name="delim"></param>
			/// <returns></returns>
			std::vector<std::string> Split(const std::string& s, char delim);
		protected:

			/// <summary>
			/// Writes a message with function arguments
			/// </summary>
			/// <param name=""></param>
			/// <param name="vec"></param>
			void Write(const std::string, std::vector<std::variant<std::string, int, float, unsigned int>> vec);

			/// <summary>
			/// Writes a message with arguments and splitters
			/// </summary>
			/// <param name="message"></param>
			/// <param name="args"></param>
			/// <param name="splitter"></param>
			void Write(const std::string message, std::string args, const char splitter);

			/// <summary>
			/// Writes a simple message to the console
			/// </summary>
			/// <param name="message"></param>
			virtual void Write(std::string message) override;
		};
	}
}

