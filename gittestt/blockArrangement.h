//
// Created by ALI on 17/02/2026.
//

#ifndef FOP_PROJECT_ALI_BLOCKARRANGEMENT_H
#define FOP_PROJECT_ALI_BLOCKARRANGEMENT_H

#include "Essentials.h"
#include "Shapes.h"
//motion blocks making
int size_motion = 15;
vector<block1> menu_block_motion(size_motion);
//looks blocks making
int size_looks = 17;
vector<block1> menu_block_looks(size_looks);
//sound block making
int size_sound = 8;
vector<block1> menu_block_sound(size_sound);
//events block making
int size_events = 8;
vector<block1> menu_block_events(size_events);
int size_control = 7;
vector<block1> menu_block_control(size_control);



//for running code
int size_under_sprite = 7;
vector<block1> under_sprite_boxes(size_under_sprite);

//for bakcground
int size_under_bkgr = 3;
vector<block1> under_sprite_bkgr(size_under_bkgr);

//for sprite
int size_under_sprt = 3;
vector<block1> under_sprite_sprt(size_under_sprt);

//for pen
int size_under_pen = 5;
vector<block1> menu_block_pen(size_under_pen);
//for operators
int size_under_operators = 18;
vector<block1> menu_block_operators(size_under_operators);
//for sensing
int size_under_sensing = 9;
vector<block1> menu_block_sensing(size_under_sensing);







void arrange(int dist, vector<block1> &blocks){



    for(int i=1; i<blocks.size(); i++){
        blocks[i].y = blocks[i-1].y + dist;
    }
}











//void pen functions
void eraseAll(SDL_Renderer * m_renderer, SDL_Texture* canvas){
    SDL_SetRenderTarget(m_renderer, canvas);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderTarget(m_renderer, nullptr);

}
void penDown(bool &penState){
    penState = true;
}
void penUp(bool &penState){
    penState = false;
}
void stamp(SDL_Renderer * m_renderer, SDL_Texture* canvas, SDL_Texture * spriteTex, SDL_Rect spritePos){
    SDL_SetRenderTarget(m_renderer, canvas);
    SDL_RenderCopy(m_renderer, spriteTex, nullptr, &spritePos);
    SDL_SetRenderTarget(m_renderer, nullptr);
}


//for sensing
void add_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = to_string(x+y);

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void subtract_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = to_string(x-y);

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void product_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = to_string(x-y);

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void divide_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = to_string(x/y);

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void random_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = to_string(rand()%(y-x)+x);

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void first_is_grater_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = x > y ? "yes" : "no";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void second_is_grater_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = x < y ? "yes" : "no";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}

void equality_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = x == y ? "yes" : "no";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void logical_and_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = x and y ? "yes" : "no";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void logical_or_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = x or y ? "yes" : "no";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void logical_not_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    string to_print = x ? "no" : "yes";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void join_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    string to_print = to_string(x) + to_string(y);
    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}

void letter_operators(SDL_Renderer * m_renderer, block1 &b){

    int y = stoi(b.input2);
    string to_print =  to_string(b.input1[y]);
    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void length_of_operators(SDL_Renderer * m_renderer, block1 &b){

    string to_print =  to_string(b.input1.length());
    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void contains_operators(SDL_Renderer * m_renderer, block1 &b){

    string to_print;
    if(b.input1.find(b.input2) != string::npos){
        to_print = "yes";
    }
    else to_print = "no";

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void mod_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);
    int y = stoi(b.input2);
    int result = x%y;
    if(result <0) result += y;
    string to_print = to_string(result);

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void abs_operators(SDL_Renderer * m_renderer, block1 &b){

    int x = stoi(b.input1);

    string to_print = to_string(abs(x));

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}
void round_operators(SDL_Renderer * m_renderer, block1 &b){

    float x = stof(b.input1);

    string to_print = to_string(round(x));

    SDL_Surface * b_surf = TTF_RenderText_Blended(b.font, to_print.c_str(), black);
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    SDL_Rect b_text_rect = {b.x, b.y + b.h, b_surf->w, b_surf->h};

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer , &b_text_rect);




    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);
    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}



#endif //FOP_PROJECT_ALI_BLOCKARRANGEMENT_H
