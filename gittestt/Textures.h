

#ifndef GITTESTT_TEXTURES_H
#define GITTESTT_TEXTURES_H


#include "Essentials.h"

//void left_ribbon(SDL_Texture* &initial_screen ,SDL_Renderer * m_renderer, SDL_DisplayMode DM){
//    initial_screen = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, DM.w, DM.h);
//    SDL_SetRenderTarget(m_renderer, initial_screen);
//    SDL_SetRenderDrawColor(m_renderer, 50, 50, 50, 255);
//    SDL_RenderClear(m_renderer);
//    SDL_Rect code_and_command_ribbon;
//    code_and_command_ribbon.h = 11 * DM.h / 12;
//    code_and_command_ribbon.w = DM.w / 15;
//    code_and_command_ribbon.x = 0;
//    code_and_command_ribbon.y = DM.h / 12;
//    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
//    SDL_RenderFillRect(m_renderer, &code_and_command_ribbon);
//    SDL_SetRenderTarget(m_renderer, nullptr);
//
//}






SDL_Color black = {0, 0, 0, 255};
SDL_Color white = {255, 255, 255, 255};
SDL_Color gray = {60, 60, 60, 255};
SDL_Color cyan = {0, 204, 204, 255};
SDL_Color dark_cyan = {0, 153, 153, 255};
SDL_Color menu_text_yellow = {251, 185, 31, 255};
SDL_Color menu_text_yellow2 = {251, 250, 31, 255};
SDL_Color blue = {0, 145, 255, 255};
SDL_Color dark_blue = {0, 40, 255, 255};
SDL_Color purple = {255, 0, 255, 255};
SDL_Color dark_purple = {190, 0, 255, 255};
SDL_Color green = {0, 255, 0, 255};
SDL_Color dark_green = {0, 200, 0, 255};
SDL_Color yellow = {255, 255, 0, 255};
SDL_Color dark_yellow = {230, 230, 20, 255};
SDL_Color orange = {255, 178, 102, 255};
SDL_Color dark_orange = {225, 153, 51, 255};
SDL_Color light_blue = {0, 218, 255, 255};
SDL_Color dark_light_blue = {17, 195, 224, 255};
SDL_Color deep_purple=  {187, 13, 207, 255};
SDL_Color dark_deep_purple=  {125, 17, 137, 255};
SDL_Color deep_orange = {255, 128, 0, 255};
SDL_Color dark_deep_orange = {204, 102, 0, 255};
SDL_Color pink = {255, 0, 127, 255};
SDL_Color dark_pink = {204, 102, 102, 255};
SDL_Color light_gray = {200, 200, 200, 255};

SDL_Texture* loadtexture(const string &path, SDL_Renderer *renderer) {
    SDL_Surface* surface = IMG_Load(path.c_str());

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

#endif //GITTESTT_TEXTURES_H
