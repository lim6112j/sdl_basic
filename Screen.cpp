#include "Screen.h"
#include <iostream>
using namespace std;
namespace sdlBasic
{
    Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

    };
    bool Screen::init(){
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            cout << "SDL init failed" << endl;
            return 1;
        }

        m_window = SDL_CreateWindow("Particle Fire Explosion",
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
        if(m_window == NULL) {
            SDL_Quit();
            return 2;
        }
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        if(m_renderer == NULL) {
            cout << "renderer made failed" << endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return 3;
        }
        if(m_texture == NULL) {
            cout << "texture made failed" << endl;
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return 4;
        }
        m_buffer = new Uint32[SCREEN_HEIGHT*SCREEN_WIDTH];
        memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
        // buffer[30000] = 0xFFFFFFFF;
        for (int i = 0; i < SCREEN_HEIGHT*SCREEN_WIDTH; i++)
        {
            m_buffer[i] = 0xFF0000FF;
        }
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        return true;
    };
    bool Screen::processEvents(){
        return false;
    };
    void Screen::close(){
        delete [] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }; 
} // namespace sdlBasic
