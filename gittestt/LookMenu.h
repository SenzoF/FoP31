//
// Created by USER on 2/17/2026.
//

#ifndef GITTESTT_LOOKMENU_H
#define GITTESTT_LOOKMENU_H

#include "Essentials.h"
#include "Shapes.h"

void say_s_for_n_sec(string s, int n , mainsprite &sprite) {

    sprite.isSayingfor = true;
    sprite.sayfortext = s;
    sprite.sayDuration = n*1000;
    sprite.sayforStartTime = SDL_GetTicks();

}

void say_s_for_n_sec_draw(SDL_Renderer *renderer, mainsprite &player2,TTF_Font *mainsaythinkfont) {

    int textX = player2.x+player2.w;
    int textY = player2.y-50;

    // SDL_Rect sayfor ={textX, textY, 100, 50};
    // SDL_SetRenderDrawColor(m_renderer, 225 , 225 , 225 , 225);
    // SDL_RenderFillRect(m_renderer, &sayfor);
    // SDL_RenderDrawRect(m_renderer, &sayfor);



    filledEllipseRGBA(renderer, textX,textY+50,15,12 ,225,225,225,255);
    aaellipseRGBA(renderer, textX,textY+50,15,12 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX+10,textY+30,40,20 ,225,225,225,255);
    aaellipseRGBA(renderer, textX+10,textY+30,40,20 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX,textY+50,14,11 ,225,225,225,255);


    // stringRGBA(m_renderer, textX-20,textY+25,player2.sayfortext.c_str(),0,0,0,255);


    SDL_Surface* saysurf1 = TTF_RenderText_Blended(mainsaythinkfont,player2.sayfortext.c_str(),black);
    SDL_Texture* saytex1 = SDL_CreateTextureFromSurface(renderer, saysurf1);
    SDL_Rect sayrect1 = {textX+10-saysurf1->w/2,textY + 30 - saysurf1->h/2,saysurf1->w,saysurf1->h};

    SDL_RenderCopy(renderer, saytex1, nullptr, &sayrect1);


}

void say_s(string s, mainsprite &sprite) {

    sprite.isSaying = true;
    sprite.saytext = s;
    sprite.sayStartTime = SDL_GetTicks();

}

void say_s_draw(SDL_Renderer *renderer, mainsprite &player2,TTF_Font *mainsaythinkfont) {

    int textX = player2.x+player2.w;
    int textY = player2.y-50;

    // SDL_Rect sayfor ={textX, textY, 100, 50};
    // SDL_SetRenderDrawColor(m_renderer, 225 , 225 , 225 , 225);
    // SDL_RenderFillRect(m_renderer, &sayfor);
    // SDL_RenderDrawRect(m_renderer, &sayfor);



    filledEllipseRGBA(renderer, textX,textY+50,15,12 ,225,225,225,255);
    aaellipseRGBA(renderer, textX,textY+50,15,12 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX+10,textY+30,40,20 ,225,225,225,255);
    aaellipseRGBA(renderer, textX+10,textY+30,40,20 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX,textY+50,14,11 ,225,225,225,255);


    // stringRGBA(m_renderer, textX-20,textY+25,player2.sayfortext.c_str(),0,0,0,255);


    SDL_Surface* saysurf1 = TTF_RenderText_Blended(mainsaythinkfont,player2.saytext.c_str(),black);
    SDL_Texture* saytex1 = SDL_CreateTextureFromSurface(renderer, saysurf1);
    SDL_Rect sayrect1 = {textX+10-saysurf1->w/2,textY + 30 - saysurf1->h/2,saysurf1->w,saysurf1->h};

    SDL_RenderCopy(renderer, saytex1, nullptr, &sayrect1);

}

void think_s_for_n_sec(string s, int n , mainsprite &sprite) {

    sprite.isThinkingfor = true;
    sprite.thinkfortext = s;
    sprite.thinkDuration = n*1000;
    sprite.thinkforStartTime = SDL_GetTicks();

}

void think_s_for_n_sec_draw(SDL_Renderer *renderer, mainsprite &player2,TTF_Font *mainsaythinkfont) {


    int textX = player2.x+player2.w;
    int textY = player2.y-50;

    // SDL_Rect sayfor ={textX, textY, 100, 50};
    // SDL_SetRenderDrawColor(m_renderer, 225 , 225 , 225 , 225);
    // SDL_RenderFillRect(m_renderer, &sayfor);
    // SDL_RenderDrawRect(m_renderer, &sayfor);



    filledEllipseRGBA(renderer, textX+10,textY+50,5,5 ,225,225,225,255);
    aaellipseRGBA(renderer, textX+10,textY+50,5,5 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX,textY+55,3,3 ,225,225,225,255);
    aaellipseRGBA(renderer, textX,textY+55,3,3 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX-8,textY+60,2,2 ,225,225,225,255);
    aaellipseRGBA(renderer, textX-8,textY+60,2,2 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX+10,textY+30,40,20 ,225,225,225,255);
    aaellipseRGBA(renderer, textX+10,textY+30,40,20 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX+10,textY+50,4,4 ,225,225,225,255);


    // stringRGBA(m_renderer, textX-20,textY+25,player2.sayfortext.c_str(),0,0,0,255);


    SDL_Surface* saysurf1 = TTF_RenderText_Blended(mainsaythinkfont,player2.thinkfortext.c_str(),black);
    SDL_Texture* saytex1 = SDL_CreateTextureFromSurface(renderer, saysurf1);
    SDL_Rect sayrect1 = {textX+10-saysurf1->w/2,textY + 30 - saysurf1->h/2,saysurf1->w,saysurf1->h};

    SDL_RenderCopy(renderer, saytex1, nullptr, &sayrect1);


}

void think_s(string s, mainsprite &sprite) {

    sprite.isThinking = true;
    sprite.thinktext = s;
    sprite.thinkStartTime = SDL_GetTicks();

}

void think_s_draw(SDL_Renderer *renderer, mainsprite &player2,TTF_Font *mainsaythinkfont) {

    int textX = player2.x+player2.w;
    int textY = player2.y-50;

    // SDL_Rect sayfor ={textX, textY, 100, 50};
    // SDL_SetRenderDrawColor(m_renderer, 225 , 225 , 225 , 225);
    // SDL_RenderFillRect(m_renderer, &sayfor);
    // SDL_RenderDrawRect(m_renderer, &sayfor);



    filledEllipseRGBA(renderer, textX+10,textY+50,5,5 ,225,225,225,255);
    aaellipseRGBA(renderer, textX+10,textY+50,5,5 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX,textY+55,3,3 ,225,225,225,255);
    aaellipseRGBA(renderer, textX,textY+55,3,3 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX-8,textY+60,2,2 ,225,225,225,255);
    aaellipseRGBA(renderer, textX-8,textY+60,2,2 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX+10,textY+30,40,20 ,225,225,225,255);
    aaellipseRGBA(renderer, textX+10,textY+30,40,20 ,100,100,100,255);

    filledEllipseRGBA(renderer, textX+10,textY+50,4,4 ,225,225,225,255);


    // stringRGBA(m_renderer, textX-20,textY+25,player2.sayfortext.c_str(),0,0,0,255);


    SDL_Surface* saysurf1 = TTF_RenderText_Blended(mainsaythinkfont,player2.thinktext.c_str(),black);
    SDL_Texture* saytex1 = SDL_CreateTextureFromSurface(renderer, saysurf1);
    SDL_Rect sayrect1 = {textX+10-saysurf1->w/2,textY + 30 - saysurf1->h/2,saysurf1->w,saysurf1->h};

    SDL_RenderCopy(renderer, saytex1, nullptr, &sayrect1);


}

#endif //GITTESTT_LOOKMENU_H