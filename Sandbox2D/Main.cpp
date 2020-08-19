#include "ThunderEngine.h"

class UbberGame : public ThunderEngine::Game {

    virtual void OnStart() override
    {
        
    }
    virtual void OnUpdate() override
    {
    }
    virtual void OnDraw() override
    {
    }
};


int main(void)
{
    UbberGame* game = new UbberGame();
    game->Run();
    delete game;

    return 0;
}