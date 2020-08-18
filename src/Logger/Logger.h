#pragma once
namespace ThunderEngine {
	namespace Logger {
		class Logger
		{
		public:
			virtual void Open() = 0;
			virtual void WriteInfo(const char* message) = 0;
			virtual void WriteWarning(const char* message) = 0;
			virtual void WriteError(const char* message) = 0;
			virtual void Close() = 0;
		};
	}
}

