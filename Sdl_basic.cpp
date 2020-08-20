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

        int elapsed = SDL_GetTicks();
        // screen.clear();

        swarm.update();
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.001))*128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.002))*128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003))*128);
        // cout << green << endl;
        const Particle * const pParticle = swarm.getParticle();
        for (int i = 0; i < Swarm::NPARTICLES; i++)
        {
            Particle particle = pParticle[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH /2;
            int y = (particle.m_y) * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
        }
        screen.boxBlur();
        // draw screen
        screen.update();
        // check for message/events
        if(screen.processEvents() == false) {
            break;
        }
    }
    
    screen.close();
    return 0;
}

