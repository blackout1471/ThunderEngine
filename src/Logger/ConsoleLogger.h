#pragma once
#include "Logger.h"
#include <iostream>
#include <Windows.h>

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
			virtual void WriteInfo(const std::string message) override;
			virtual void WriteWarning(const std::string message) override;
			virtual void WriteError(const std::string message) override;
		private:
			bool IsConsoleAttached();
			DWORD GetCurrentConsoleId();
			void CreateConsole();
		protected:
			virtual void Write(const std::string message) override;
		};
	}
}

