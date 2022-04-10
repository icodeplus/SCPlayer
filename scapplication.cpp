#include "scapplication.h"
#include "SDL.h"

SCApplication::SCApplication()
{
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS);
}

SCApplication::~SCApplication()
{
    SDL_Quit();
}

void SCApplication::Run()
{
    bool bRunning = true;
    SDL_Event event;

    while (bRunning)
    {
        while (0 != SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                bRunning = false;
                break;
            }
        }
    }
}
