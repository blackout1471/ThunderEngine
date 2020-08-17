#include "ThunderEngine.h"
#include "Platform/RenderApi.h"

using ThunderEngine::Application::Debug;

int main(void)
{

    ThunderEngine::Application::GameWindow* gameWindow = new ThunderEngine::Application::GameWindow();

    gameWindow->CreateWindow(640,320,"Yes", NULL, NULL);
    gameWindow->MakeContextCurrent();

    ThunderEngine::RenderApi::CreateApi(ThunderEngine::RenderVendor::OpenGL);
    ThunderEngine::RenderApi::GetApi()->Init();

    while (!gameWindow->ShouldWindowClose())
    {
        ThunderEngine::RenderApi::GetApi()->ClearColor(.0, .0, .8, 1.0);
        ThunderEngine::RenderApi::GetApi()->ClearColorBit();
        gameWindow->SwapBuffers();
        gameWindow->PollEvents();
    }
    return 0;
}