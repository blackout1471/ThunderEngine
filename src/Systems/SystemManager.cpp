#pragma once
#include "tepch.h"
#include "SystemManager.h"

#include "Renderer2D.h"

namespace ThunderEngine {
	namespace System {
		std::shared_ptr<SystemManager> SystemManager::s_SystemManager = nullptr;

		SystemManager::SystemManager()
		{
			m_Systems = std::vector<System*>();
			
			this->AddSystem(new Renderer2D());
		}

		SystemManager::~SystemManager()
		{
			for (auto& system : m_Systems)
				delete system;

			m_Systems.clear();
		}

		void SystemManager::OnStart()
		{
			for (auto& system : m_Systems)
				system->OnStart();
		}

		void SystemManager::OnUpdate()
		{
			for (auto& system : m_Systems)
				system->OnUpdate();
		}

		void SystemManager::OnDraw()
		{
			for (auto& system : m_Systems)
				system->OnDraw();
		}

		void SystemManager::AddSystem(System* system)
		{
			m_Systems.push_back(system);
		}


		void SystemManager::InitSystems()
		{
			s_SystemManager = std::make_shared<SystemManager>();
		}
	}
}