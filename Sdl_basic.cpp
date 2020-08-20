#include<iostream>
#include<SDL2/SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include "Swarm.h"
using namespace std;
using namespace sdlBasic;
int main() {
    
    srand(time(NULL));
    Screen screen;
    if(screen.init() == false){
        cout << "error initializing SDL" << endl;
    }
    Swarm swarm;
    while (true)
    {
        // update particle
        // draw particle
        // check for message/events
        int elapsed = SDL_GetTicks();
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.001))*128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.002))*128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003))*128);
        // cout << green << endl;
        const Particle * const pParticle = swarm.getParticle();
        for (int i = 0; i < Swarm::NPARTICLES; i++)
        {
            Particle particle = pParticle[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH /2;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
        }
        

        // for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        // {
        //     for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
        //     {
        //         screen->setPixel(x, y, red, green, blue); 
        //     }
            
        // }
        screen.update();
        if(screen.processEvents() == false) {
            break;
        }
    }
    
    screen.close();
    return 0;
}

