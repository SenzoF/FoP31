//
// Created by USER on 2/25/2026.
//

#ifndef FOP_MAIN_PROJECT_SOROUSH_COSTUMESTAB_H
#define FOP_MAIN_PROJECT_SOROUSH_COSTUMESTAB_H
#include "Essentials.h"

bool isinsideboard(SDL_Rect board, int x , int y)
{
    if (x >= board.x && x<=board.x + board.w && y >= board.y && y<=board.y + board.h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct Board
{
    SDL_Rect area;

    bool drawing =false;

    int brushsize = 4;
    SDL_Color brushcolor={0,0,0,255};

    void initcostume(SDL_Renderer* render,int x,int y , int w, int h)
    {
        area={x,y,w,h};

    }

    void handleclicked(SDL_Event &e,SDL_Renderer* renderer)
    {
        int mx,my;
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {

            if (e.button.button == SDL_BUTTON_LEFT)
            {
                mx = e.button.x;
                my = e.button.y;
                SDL_Point p ={mx,my};

                if (SDL_PointInRect(&p,&area))
                {
                    drawing=true;
                }
            }
        }
        if (e.type == SDL_MOUSEBUTTONUP)
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                drawing=false;
            }
        }
        if (e.type == SDL_MOUSEMOTION)
        {
            if (drawing)
            {
                mx=e.motion.x;
                my=e.motion.y;
                SDL_Point p ={mx,my};

                if (SDL_PointInRect(&p,&area))
                {
                    mx = e.motion.x;
                    my = e.motion.y;
                    draw(renderer,mx , my);
                }
            }
        }
    }

    void draw(SDL_Renderer* render, int x , int y)
    {
        for (int dy = -brushsize/2; dy<=brushsize/2; dy++)
        {
            for (int dx = -brushsize/2; dx<=brushsize/2; dx++)
            {
                int px= x+dx;
                int py = y+dy;
                if (px>=area.x && px<=area.x+area.w && py>=area.y && py<=area.y+area.h)
                {
                    SDL_RenderDrawPoint(render,px,py);
                }
            }
        }
    }

    void rendercostume(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderDrawRect(renderer,&area);
    }


};



#endif //FOP_MAIN_PROJECT_SOROUSH_COSTUMESTAB_H