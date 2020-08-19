#pragma once
#include <Logger/ConsoleLogger.h>

namespace ThunderEngine {
	namespace Application {
		class Log
		{
		private:
			static std::shared_ptr<Logger::Logger> s_Logger;

		public:
			inline static std::shared_ptr<Logger::Logger>& GetLogger() { return s_Logger; }
		};
	}
}

#define TE_LOG_INFO(...)		::ThunderEngine::Application::Log::GetLogger()->WriteInfo(__VA_ARGS__)
#define TE_LOG_WARN(...)		::ThunderEngine::Application::Log::GetLogger()->WriteWarning(__VA_ARGS__)
#define TE_LOG_ERROR(...)		::ThunderEngine::Application::Log::GetLogger()->WriteError(__VA_ARGS__)