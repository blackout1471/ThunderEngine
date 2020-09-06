#include "ThunderEngine.h"

class FirstScene : public ThunderEngine::Entity::Scene {

    ThunderEngine::Entity::Entity c;
    ThunderEngine::Entity::Entity c2;
    ThunderEngine::Entity::Entity c3;
    float time = 0;

    virtual void OnStart() override
    {
        ThunderEngine::Entity::Entity camera = CreateEntity();
        camera.AddComponent<ThunderEngine::Component::OrthographicCameraComponent>();

        c = CreateEntity();
        auto& test = c.AddComponent<ThunderEngine::Component::QuadComponent>(50, glm::vec4(1.f, 1.f, 1.f, 1.f));

        auto& ct = c.GetComponent<ThunderEngine::Component::TransformComponent>();
        ct.Transform.SetPosition(glm::vec3(200.f, 200.f, 1.f));

        c2 = CreateEntity();
        c2.AddComponent<ThunderEngine::Component::QuadComponent>(50, glm::vec4(1.f, 0.f, 0.f, 1.f));

        auto& ct2 = c2.GetComponent<ThunderEngine::Component::TransformComponent>();
        ct2.Transform.SetPosition(glm::vec3(350.f, 200.f, 1.f));

        c3 = CreateEntity();
        c3.AddComponent<ThunderEngine::Component::QuadComponent>(50, glm::vec4(0.f, 1.f, 0.f, 1.f));

        auto& ct3 = c3.GetComponent<ThunderEngine::Component::TransformComponent>();
        ct3.Transform.SetPosition(glm::vec3(500.f, 200.f, 1.f));
    }

    virtual void OnUpdate() override
    {
        time += ThunderEngine::Time::GetDeltaTime();
        auto& ct = c.GetComponent<ThunderEngine::Component::TransformComponent>();
        auto& ct2 = c2.GetComponent<ThunderEngine::Component::TransformComponent>();
        auto& ct3 = c3.GetComponent<ThunderEngine::Component::TransformComponent>();

        float rotationSpeed = 1.f;
        float translationSpeed = 20.f;
        float scaleSpeed = 0.1f;

        if (time < 5.f)
        {
            ct.Transform.Rotate(glm::vec3(0.f, 0.f, rotationSpeed) * ThunderEngine::Time::GetDeltaTime());
            ct.Transform.Translate(glm::vec3(translationSpeed, 0.f, 0.f) * ThunderEngine::Time::GetDeltaTime());
            ct.Transform.Scale(glm::vec3(scaleSpeed, scaleSpeed, 0.f) * ThunderEngine::Time::GetDeltaTime());

            ct2.Transform.Rotate(glm::vec3(0.f, 0.f, rotationSpeed) * ThunderEngine::Time::GetDeltaTime());
            ct2.Transform.Translate(glm::vec3(translationSpeed, 0.f, 0.f) * ThunderEngine::Time::GetDeltaTime());
            ct2.Transform.Scale(glm::vec3(scaleSpeed, scaleSpeed, 0.f) * ThunderEngine::Time::GetDeltaTime());

            ct3.Transform.Rotate(glm::vec3(0.f, 0.f, rotationSpeed) * ThunderEngine::Time::GetDeltaTime());
            ct3.Transform.Translate(glm::vec3(translationSpeed, 0.f, 0.f) * ThunderEngine::Time::GetDeltaTime());
            ct3.Transform.Scale(glm::vec3(scaleSpeed, scaleSpeed, 0.f) * ThunderEngine::Time::GetDeltaTime());
        }
        else if (time > 5.f && time < 10.f)
        {
            ct.Transform.Rotate(glm::vec3(0.f, 0.f, -rotationSpeed) * ThunderEngine::Time::GetDeltaTime());
            ct.Transform.Translate(glm::vec3(-translationSpeed, 0.f, 0.f) * ThunderEngine::Time::GetDeltaTime());
            ct.Transform.Scale(glm::vec3(-scaleSpeed, -scaleSpeed, 0.f) * ThunderEngine::Time::GetDeltaTime());

            ct2.Transform.Rotate(glm::vec3(0.f, 0.f, -rotationSpeed) * ThunderEngine::Time::GetDeltaTime());
            ct2.Transform.Translate(glm::vec3(-translationSpeed, 0.f, 0.f) * ThunderEngine::Time::GetDeltaTime());
            ct2.Transform.Scale(glm::vec3(-scaleSpeed, -scaleSpeed, 0.f) * ThunderEngine::Time::GetDeltaTime());

            ct3.Transform.Rotate(glm::vec3(0.f, 0.f, -rotationSpeed) * ThunderEngine::Time::GetDeltaTime());
            ct3.Transform.Translate(glm::vec3(-translationSpeed, 0.f, 0.f) * ThunderEngine::Time::GetDeltaTime());
            ct3.Transform.Scale(glm::vec3(-scaleSpeed, -scaleSpeed, 0.f) * ThunderEngine::Time::GetDeltaTime());
        }
        else if (time > 10.f)
            time = 0;

        
        
        
    }
};

class UbberGame : public ThunderEngine::Game {

    virtual void OnStart() override
    {
        ThunderEngine::Entity::SceneManager::GetScenes()->ChangeScene<FirstScene>();
    }

    virtual void OnUpdate() override
    {
        ThunderEngine::Entity::SceneManager::GetScenes()->GetCurrentScene()->OnUpdate();
    }
};


int main(void)
{
    UbberGame* game = new UbberGame();
    game->Run();

    return 0;
}