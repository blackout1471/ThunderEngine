#pragma once
#include "GameWindow.h"

namespace ThunderEngine {
	class Game
	{
	private:
		bool m_IsRunning;
		Application::GameWindow* m_WindowInstance;
	public:
		Game();
		virtual ~Game();
		void Run();
	public:
		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
	private:
		void OnGameWindowEvent(Events::Event& ev);
	};
}