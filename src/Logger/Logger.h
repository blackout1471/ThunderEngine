#pragma once
namespace ThunderEngine {
	namespace Logger {
		class Logger
		{
		protected:
			virtual void Write(std::string message) = 0;
		public:
			virtual void Open() = 0;
			virtual void WriteInfo(const std::string message, std::string args, const char splitter) = 0;
			virtual void WriteWarning(const std::string message, std::string args, const char splitter) = 0;
			virtual void WriteError(const std::string message, std::string args, const char splitter) = 0;
			virtual void Close() = 0;
		};
	}
}

