#pragma once
#include <SDL2/SDL.h>

struct Vec2
{
    float x;
    float y;
};

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
    
    //SDL
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    bool isRunning;
    Vec2 paddlePos;
    Vec2 ballPos;
};
