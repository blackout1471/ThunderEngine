#include "tepch.h"
#include "Game.h"
#include <Graphics/RenderApi.h>
#include "Core/Core.h"
#include "Time.h"
#include <Systems/SystemManager.h>
#include <Entity/SceneManager.h>

#include <Utils/FileUtils.h>

namespace ThunderEngine {

	Game::Game() : m_IsRunning(true), m_WindowInstance(nullptr)
	{
        m_WindowInstance = new Application::GameWindow();
	}

	Game::~Game()
	{
		delete m_WindowInstance;
	}

	void Game::Run()
	{
        // Create game window
        TE_ASSERT(m_WindowInstance->CreateGameWindow(Application::GameWindowSpecifications(800, 600, "Yes", false), nullptr, nullptr), "Window couldn't be created", { "" });
        TE_LOG_INFO("Window created Width: {} Height: {}", {m_WindowInstance->GetWidth(), m_WindowInstance->GetHeight()});

        // Set window event handler
        m_WindowInstance->SetEventHandler(std::bind(&Game::OnGameWindowEvent, this, std::placeholders::_1));
        
        m_WindowInstance->MakeContextCurrent(); // Make it the target to draw to
        
        // Create the API, either CPU | Opengl | DirectX
        Graphics::RenderApi::CreateApi(Graphics::RenderVendor::OpenGL);
        TE_ASSERT(Graphics::RenderApi::GetApi()->Init(), "Could not create initialise renderer context", {});

        m_WindowInstance->SetVSync(true);

        OnStart();

        // Init systems
        System::SystemManager::InitSystems();
        System::SystemManager::GetSystems()->OnStart();

        float t1, t2;
        t1 = t2 = Time::GetCurrentProcessTime();

        while (!m_WindowInstance->ShouldWindowClose())
        {
            // Get delta time
            t2 = Time::GetCurrentProcessTime();
            Time::SetDeltaTime(t2 - t1);
            t1 = t2;
            OnUpdate();
            Entity::SceneManager::GetScenes()->GetCurrentScene()->OnUpdate();

            // Update systems
            System::SystemManager::GetSystems()->OnUpdate();
            System::SystemManager::GetSystems()->OnDraw();

            // Swap to the buffer being written to
            m_WindowInstance->SwapBuffers();
            m_WindowInstance->PollEvents(); // Get window events and process
        }
	}

    void Game::OnGameWindowEvent(Events::Event& ev)
    {
        TE_LOG_INFO(ev.ToString(), {});
    }
}