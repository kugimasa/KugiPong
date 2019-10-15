#pragma once
#include <SDL2/SDL.h>
#include <iostream>

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
    
    Uint32 ticksCount;
    
    bool isRunning;
    int paddleDir;
    Vec2 paddlePos;
    Vec2 ballPos;
    Vec2 ballVel;
};
