#include "tepch.h"
#include "Debug.h"


namespace ThunderEngine {
	namespace Application {

		void ThunderEngine::Application::Debug::Write(char* text) {
			std::cout << text;
		}

	}
}