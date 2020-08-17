#include "ThunderEngine.h"

using ThunderEngine::Application::Debug;

int main(void)
{

    Application::GameWindow* gameWindow = new Application::GameWindow();
    Debug debug;
    debug.Write("hello ");

    gameWindow->CreateWindow(640,320,"Yes", NULL, NULL);
    while (!gameWindow->ShouldWindowClose())
    {
        gameWindow->SwapBuffers();
        gameWindow->PollEvents();
    }
    return 0;
}