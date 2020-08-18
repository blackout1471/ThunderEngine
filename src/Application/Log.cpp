#include "tepch.h"
#include "Log.h"

namespace ThunderEngine {
	namespace Application {

		std::shared_ptr<Logger::Logger> Log::s_Logger = std::make_shared < Logger::ConsoleLogger>();
	}
}