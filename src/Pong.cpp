#include "Pong.h"

Pong::Pong()
{

}

bool Pong::Initialize()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Cannot init SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("KugiPong",
                              100,100,
                              1024,768,
                              0);
    if(!window)
    {
        SDL_Log("Cannot create window: %s", SDL_GetError());
        return false;
    }
    
    return true;
}

void Pong::RunLoop()
{
    while(isRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Pong::Shutdown()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Pong::ProcessInput()
{
    
}

void Pong::UpdateGame()
{
    
}

void Pong::GenerateOutput()
{
    
}

