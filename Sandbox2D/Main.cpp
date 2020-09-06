#include "ThunderEngine.h"
#include "glm/gtc/matrix_transform.hpp"

class FirstScene : public ThunderEngine::Entity::Scene {

    virtual void OnStart() override
    {
        ThunderEngine::Entity::Entity camera = CreateEntity();
        camera.AddComponent<ThunderEngine::Component::OrthographicCameraComponent>();


        ThunderEngine::Entity::Entity asd = CreateEntity();
        asd.AddComponent<ThunderEngine::Component::Test2DQuadComponent>(50, glm::vec4(1.f, 0.f, 0.f, 1.f));
        ThunderEngine::Component::TransformComponent& trans = asd.GetComponent<ThunderEngine::Component::TransformComponent>();
        trans.Transform[3][0] = 200.f;
        trans.Transform[3][1] = 200.f;

        ThunderEngine::Entity::Entity b = CreateEntity();
        b.AddComponent<ThunderEngine::Component::Test2DQuadComponent>(100, glm::vec4(1.f, 1.f, 0.f, 1.f));

        ThunderEngine::Entity::Entity c = CreateEntity();
        c.AddComponent<ThunderEngine::Component::Test2DQuadComponent>(200, glm::vec4(1.f, 1.f, 1.f, 1.f));
    }

    virtual void OnUpdate() override
    {
    }
};

class UbberGame : public ThunderEngine::Game {

    virtual void OnStart() override
    {
        ThunderEngine::Entity::SceneManager::GetScenes()->ChangeScene<FirstScene>();
    }

    virtual void OnUpdate() override
    {
    }
};


int main(void)
{
    UbberGame* game = new UbberGame();
    game->Run();

    return 0;
}