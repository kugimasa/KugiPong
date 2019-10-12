#include "Pong.h"

const int winW = 450;
const int winH = 640;
const int thickness = 40;
const float paddleSize = 300.0f;


Pong::Pong()
:window(nullptr)
,renderer(nullptr)
,isRunning(true)
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
    
    //Create Window
    window = SDL_CreateWindow("KugiPong",
                              100,100,
                              winW,winH,
                              0);
    if(!window)
    {
        SDL_Log("Cannot create window: %s", SDL_GetError());
        return false;
    }
    
    //Create Renderer
    renderer  = SDL_CreateRenderer(window,
                                   -1,
                                   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Initialize parameter
    paddlePos.x = winW/2.0f;
    paddlePos.y = winH - thickness;
    ballPos.x = winW/2.0f;
    ballPos.y = winH/2.0f;
    
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
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Pong::ProcessInput()
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }
    
    //Check keyboard state
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE])
    {
        isRunning = false;
    }
}

void Pong::UpdateGame()
{
    
}

void Pong::GenerateOutput()
{
    //BackGround color
    SDL_SetRenderDrawColor(renderer,
                           68,   //R
                           114,   //G
                           196, //B
                           255  //A
                           );
    //Clear Buffer with BackGround color
    SDL_RenderClear(renderer);
    
    //Wall color
    SDL_SetRenderDrawColor(renderer, 208, 206, 206, 255);
    SDL_Rect wall{
        0,
        0,
        winW,
        thickness
    };
    SDL_RenderFillRect(renderer, &wall);
    
    //Draw right wall
    wall.x = 0;
    wall.y = 0;
    wall.w = thickness;
    wall.h = winH;
    SDL_RenderFillRect(renderer, &wall);
    
    //Draw left wall
    wall.x = winW - thickness;
    wall.y = 0;
    wall.w = thickness;
    wall.h = winH;
    SDL_RenderFillRect(renderer, &wall);
    
    //Paddle
    SDL_SetRenderDrawColor(renderer, 254, 248, 84, 255);
    SDL_Rect paddle{
        static_cast<int>(paddlePos.x - paddleSize/2),
        static_cast<int>(paddlePos.y),
        static_cast<int>(paddleSize),
        thickness
    };
    SDL_RenderFillRect(renderer, &paddle);
    
    //Ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect ball{
        static_cast<int>(ballPos.x - thickness/2),
        static_cast<int>(ballPos.y - thickness/2),
        thickness,
        thickness
    };
    SDL_RenderFillRect(renderer, &ball);
    
    //Swap front-buffer and back-buffer
    SDL_RenderPresent(renderer);
}

