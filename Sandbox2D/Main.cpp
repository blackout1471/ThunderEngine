#include "ThunderEngine.h"

int main(void)
{

    Application::GameWindow* gameWindow = new Application::GameWindow();

    gameWindow->CreateWindow(640,320,"Yes", NULL, NULL);
    while (!gameWindow->ShouldWindowClose())
    {
        gameWindow->SwapBuffers();
        gameWindow->PollEvents();
    }
    return 0;
}