#pragma once
#include <SDL2/SDL.h>

class Pong
{
public:
    Pong();
    bool Initialize();
    void RunLoop();
    void Shutdown();
private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    
    // SDL Window
    SDL_Window* window;
    bool isRunning;
};
