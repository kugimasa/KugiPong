#include "Pong.h"

int main(int argc, char** argv)
{
    Pong pong;
    bool success = pong.Initialize();
    if (success)
    {
        pong.RunLoop();
    }
    pong.Shutdown();
    return 0; 
}
