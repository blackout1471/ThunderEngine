#pragma once
#include <tepch.h>

namespace ThunderEngine {
	namespace Events {
		class Event {
		public:
			bool Handled = false;
			virtual const char* GetName() const = 0;

			virtual std::string ToString() const { return GetName(); }
		};
	}
}