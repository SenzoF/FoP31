//
// Created by USER on 2/17/2026.
//

#ifndef GITTESTT_SOUNDMENU_H
#define GITTESTT_SOUNDMENU_H

#include "Essentials.h"
#include "Shapes.h"

Mix_Chunk* Meow1 = Mix_LoadWAV("sounds/meow.wav");


void playsound_until(Mix_Chunk* sound) {

    if (!sound) return;
    int channel = Mix_PlayChannel(-1, sound, 0);
    if (channel == -1) return;

    while (Mix_Playing(channel)) {
        SDL_Delay(10);
    }

}

void playsound(Mix_Chunk* sound) {

    Mix_PlayChannel(-1,sound,0);

}

void stopAllSound() {
    Mix_HaltChannel(-1);
}

// void change_s_effect_by_n(string s , int n , Mix_Chunk* sound) {
//     if (s == "pitch") {
//
//         Mix_OpenAudio(22000, MIX_DEFAULT_FORMAT, 2, 2048);
//     }
// }

#endif //GITTESTT_SOUNDMENU_H