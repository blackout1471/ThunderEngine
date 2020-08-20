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
			virtual void Open() override;
			virtual void Close() override;
			virtual void WriteInfo(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) override;
			virtual void WriteWarning(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) override;
			virtual void WriteError(const std::string message, std::vector<std::variant<std::string, int, float, unsigned int>> vec) override;
		private:
			bool IsConsoleAttached();
			DWORD GetCurrentConsoleId();
			void CreateConsole();
			bool Replace(std::string& str, const std::string& from, const std::string& to);
			std::string Format(std::string text, std::string args, const char splitter);
			std::vector<std::string> Split(const std::string& s, char delim);
		protected:
			void Write(const std::string, std::vector<std::variant<std::string, int, float, unsigned int>> vec);
			void Write(const std::string message, std::string args, const char splitter);
			virtual void Write(std::string message) override;
		};
	}
}

