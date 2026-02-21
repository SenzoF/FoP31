//
// Created by USER on 2/17/2026.
//

#ifndef GITTESTT_MOTION_H
#define GITTESTT_MOTION_H


#include "Essentials.h"
#include "Shapes.h"

//void move_n_step(bool isFacingRight, int n, mainsprite &sprite) {
//
//    if (isFacingRight) {
//        for (int i = 0; i < n; i++) {
//            sprite.x += 1;
//        }
//
//    }
//    else {
//        for (int i = 0; i < n; i++) {
//            sprite.x -= 1;
//        }
//    }
//
//}

void move_n_step(double angle, int n, mainsprite &sprite) {
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    SDL_Point point = {sprite.x , sprite.y};
    if(SDL_PointInRect(&point, &where_boundry)){
        double rad = angle * M_PI / 180;
        sprite.x += int(cos(rad) * n);
        sprite.y += int(sin(rad) * n);
    }

}

void turn_right_n_degree(double n,mainsprite &sprite) {
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    SDL_Point point = {sprite.x , sprite.y};
    if(SDL_PointInRect(&point, &where_boundry)){
        double angle = n;
        sprite.angle += angle;
    }

}
void turn_left_n_degree(double n,mainsprite &sprite) {
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    SDL_Point point = {sprite.x , sprite.y};
    if(SDL_PointInRect(&point, &where_boundry)){
        double angle = n;
        sprite.angle -= angle;
    }

}

void go_to_pos(string &which, mainsprite &sprite, SDL_Point & curser){
    SDL_Rect where_mouse = {1025, 128, 895, 532};
    if(which == "random position"){
        int n = 1920, m = 1025;
        srand(time(nullptr));
        sprite.x += rand() % (n-m) + m;
        n = 660, m = 128;
        sprite.y += rand() % (n-m) + m;
    }
    else if(which == "mouse pointer" and SDL_PointInRect(&curser, &where_mouse)){
        sprite.x = curser.x;
        sprite.y = curser.y;
    }

}

void go_to_cor(int x, int y, mainsprite &sprite){
    x+=1450;
    y+=350;
    SDL_Rect where_to = {1025, 128, 895, 532};
    SDL_Point point = {x, y};
    if(SDL_PointInRect(&point, &where_to)){
        sprite.x = x;
        sprite.y = y;
    }
}

//void glide(int t, string &which, SDL_Point &curser, mainsprite &sprite){
//    SDL_Rect where_boundry = {1025, 128, 895, 532};
//    int x=0, y=0;
//    if(which == "random position"){
//        srand(time(nullptr));
//        int n = 1920, m = 1025;
//        x = rand() % (n-m) + m;
//        n = 660, m = 128;
//        y = rand() % (n-m) + m;
//    }
//    else if(which == "mouse pointer"){
//        x = curser.x;
//        y = curser.y;
//    }
//    int d = int(sqrt((x - sprite.x) * (x - sprite.x) + (y - sprite.y) * (y - sprite.y)));
//
//
//}

void point_in_direction(int angle, mainsprite &sprite){
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    SDL_Point point = {sprite.x , sprite.y};
    if(SDL_PointInRect(&point, &where_boundry)){
        sprite.angle = angle;
    }

}
void point_towards(string &which, SDL_Point curser, mainsprite &sprite){
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    SDL_Point point = {curser.x, curser.y};
    if(which == "mouse" and SDL_PointInRect(&point, &where_boundry)){
        sprite.angle = -atan((sprite.x - curser.x) / (sprite.y - curser.y)) * 180 / (M_PI);
    }
}
void change_x_by(int x, mainsprite &sprite){
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    int X = x + sprite.x;
    if(X >= where_boundry.x and X <= where_boundry.x + where_boundry.w){
        sprite.x = X;
    }

}
void set_x_to(int X, mainsprite &sprite){
    X+=1450;
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    if(X >= where_boundry.x and X <= where_boundry.x + where_boundry.w){
        sprite.x = X;
    }
}
void change_y_by(int y, mainsprite &sprite){
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    int Y = y + sprite.y;
    if(Y >= where_boundry.y and Y <= where_boundry.y + where_boundry.h){
        sprite.y = Y;
    }
}
void set_y_to(int Y, mainsprite &sprite){
    Y += 350;
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    if(Y >= where_boundry.y and Y <= where_boundry.y + where_boundry.h){
        sprite.y = Y;
    }
}
//void if_on_edge_bounce(mainsprite &sprite){
//    if(sprite.x >= 1900 or sprite.x <= 1050 or sprite.y <= 140 or sprite.y >= 600){
//        sprite.flip = SDL_FLIP_HORIZONTAL;
////        sprite.flip = SDL_FLIP_VERTICAL;
//        sprite.angle += 180;
//    }
////    sprite.flip = SDL_FLIP_NONE;
//}

//soroush's code for edge bounce.it does not work.
void if_on_edge_bounce(mainsprite &sprite)
{
    SDL_Rect where_boundry = {1025, 128, 895, 532};
    SDL_Point point = {sprite.x , sprite.y};

    if (sprite.x <=where_boundry.x || sprite.x >= where_boundry.x + where_boundry.w)
    {
        sprite.angle = 180 - sprite.angle;
    }
    if (sprite.y <=where_boundry.y || sprite.y >= where_boundry.y + where_boundry.h)
    {
        sprite.angle *= -1;
    }
}










#endif //GITTESTT_MOTION_H