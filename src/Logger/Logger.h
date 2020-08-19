#pragma once
namespace ThunderEngine {
	namespace Logger {
		class Logger
		{
		protected:
			virtual void Write(const std::string message) = 0;
		public:
			virtual void Open() = 0;
			virtual void WriteInfo(const std::string message) = 0;
			virtual void WriteWarning(const std::string message) = 0;
			virtual void WriteError(const std::string message) = 0;
			virtual void Close() = 0;
		};
	}
}

