#include<iostream>
#include<SDL2/SDL.h>
#include "Screen.h"
using namespace std;
int main() {
    
    sdlBasic::Screen *screen;
    screen->init();
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        // update particle
        // draw particle
        // check for message/events
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }
    screen->close();
    return 0;
}

