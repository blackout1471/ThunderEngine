#include "ThunderEngine.h"
class FirstScene : public ThunderEngine::Entity::Scene {

    virtual void OnStart() override
    {
        ThunderEngine::Entity::Entity asd = CreateEntity();
        asd.AddComponent<ThunderEngine::Component::Test2DQuadComponent>(0.1, glm::vec4(1.f, 0.f, 0.f, 1.f));

        ThunderEngine::Entity::Entity b = CreateEntity();
        b.AddComponent<ThunderEngine::Component::Test2DQuadComponent>(0.2, glm::vec4(1.f, 1.f, 0.f, 1.f));

        ThunderEngine::Entity::Entity c = CreateEntity();
        c.AddComponent<ThunderEngine::Component::Test2DQuadComponent>(0.3, glm::vec4(1.f, 1.f, 1.f, 1.f));
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