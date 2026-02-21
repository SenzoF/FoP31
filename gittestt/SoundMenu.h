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
int systemvolume=128;

void change_volume_by(int volume)
{
    systemvolume += volume;
    if (systemvolume < 0) systemvolume = 0;
    if (systemvolume > 128) systemvolume = 128;
    Mix_Volume(-1,systemvolume);
}

void set_volume(int volume)
{
    Mix_Volume(-1,volume);
}

#endif //GITTESTT_SOUNDMENU_H