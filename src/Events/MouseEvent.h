#pragma once
#include "Event.h"
#include <Application/MouseButton.h>
#include <sstream>

namespace ThunderEngine {
	namespace Events {
		class MousePressedEvent : public Event
		{
		private:
			MouseButton m_Key;
			int m_Mods;
		public:
			MousePressedEvent(MouseButton key, int mods)
				: m_Key(key), m_Mods(mods) {};
		public:
			inline virtual const char* GetName() const override
			{
				return std::string("MousePressedEvent").c_str();
			}

			inline virtual std::string ToString() const override {
				std::stringstream ss;

				ss << "MousePressedEvent " << m_Key;

				return ss.str();
			}
		};

		class MouseReleasedEvent : public Event
		{
		private:
			MouseButton m_Key;
			int m_Mods;
		public:
			MouseReleasedEvent(MouseButton key, int mods)
				: m_Key(key), m_Mods(mods) {};
		public:
			inline virtual const char* GetName() const override
			{
				return std::string("MouseReleasedEvent").c_str();
			}

			inline virtual std::string ToString() const override {
				std::stringstream ss;

				ss << "MouseReleasedEvent " << m_Key;

				return ss.str();
			}
		};

		class MouseRepeatEvent : public Event
		{
		private:
			MouseButton m_Key;
			int m_Mods;
		public:
			MouseRepeatEvent(MouseButton key, int mods)
				: m_Key(key), m_Mods(mods) {};
		public:

			inline virtual const char* GetName() const override {
				return std::string("MouseRepeatEvent").c_str();
			};

			inline virtual std::string ToString() const override {
				std::stringstream ss;

				ss << "MouseRepeatEvent " << m_Key;

				return ss.str();
			}
		};
	}
}