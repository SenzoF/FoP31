//
// Created by USER on 2/17/2026.
//

#ifndef GITTESTT_SHAPES_H
#define GITTESTT_SHAPES_H


#include "Essentials.h"
const double shadow_factor = 0.7;
const double border_factor = 0.85;
struct Circle {
    int x, y, r;
};
struct CurveyRect {
    int x, y, r, w, h;

};
struct CompleteCurveyRect {
    int x, y, r, w, h;
};
struct RibbonButton {
    int x=0, y=0, r=0;
    vector<Sint16> X = vector<Sint16>(6, 0);
    vector<Sint16> Y = vector<Sint16>(6, 0);
    //I have to use a function in a struct.
    void vertices(){
        for(int i=0; i<6; i++){
            X[i] = x - r * cos((2 * M_PI * i) / 6);
            Y[i] = y - r * sin((2 * M_PI * i) / 6);
        }
    }

};
struct block1 {
    int x, y, w, h;
    SDL_Color color;
    string input1;
    string input2;
    SDL_Rect text_box1;
    SDL_Rect text_box2;
    bool isFocused1 = false;
    bool isFocused2 = false;
    string opCode;
    block1* next = nullptr;
    TTF_Font * font;
};
struct block2 {
    int x, y, w, h;
    SDL_Color color;
    string input;
    vector<SDL_Rect> box;
};






//sprites

struct mainsprite {
    int x, y, w, h;


    SDL_Texture* texture;
    double angle=0;
    SDL_RendererFlip flip =SDL_FLIP_NONE;
    SDL_Point center;

    void setcenter() {
        center.x = w/2;
        center.y = h/2;
    }


    bool isFacingRight;


    bool isSayingfor=false;
    bool isSaying=false;
    string saytext = "";
    string sayfortext = "";
    Uint32 sayStartTime = 0;
    Uint32 sayforStartTime = 0;
    Uint32 sayDuration = 0;


    bool isThinkingfor=false;
    bool isThinking=false;
    string thinktext = "";
    string thinkfortext = "";
    Uint32 thinkStartTime = 0;
    Uint32 thinkforStartTime = 0;
    Uint32 thinkDuration = 0;




};





//helper
int shadow(int color){
    return int(color* shadow_factor);
}
int border(int color){
    return int(color* border_factor);
}
//basic geometry drawing
void aaFilledSemi_circle(SDL_Renderer * m_renderer, int x, int y, int r, int red, int green, int blue, int alpha, int position){
    switch (position) {
        case 1:{
            SDL_Rect box = {x - r, y - r, 2 * r + 1, r};
            SDL_RenderSetClipRect(m_renderer, &box);
            filledCircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha/2);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 2:{
            SDL_Rect box = {x - r, y, 2 * r + 1, r+1};
            SDL_RenderSetClipRect(m_renderer, &box);
            filledCircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha/2);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        default: break;
    }

}
void aaFilledQuarter_circle(SDL_Renderer * m_renderer, int x, int y, int r, int red, int green, int blue, int alpha, int position){
    switch (position) {
        case 1:{
            SDL_Rect box = {x, y - r, r + 1, r};
            SDL_RenderSetClipRect(m_renderer, &box);
            filledCircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha/2);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 2:{
            SDL_Rect box = {x-r, y - r, r + 1, r};
            SDL_RenderSetClipRect(m_renderer, &box);
            filledCircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha/2);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 3:{
            SDL_Rect box = {x, y, r + 1, r+1};
            SDL_RenderSetClipRect(m_renderer, &box);
            filledCircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha/2);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 4:{
            SDL_Rect box = {x-r, y, r + 1, r+1};
            SDL_RenderSetClipRect(m_renderer, &box);
            filledCircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha/2);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        default: break;
    }
}
void aaSemi_circle(SDL_Renderer * m_renderer, int x, int y, int r, int red, int green, int blue, int alpha, int position){
    switch (position) {
        case 1:{
            SDL_Rect box = {x - r, y - r, 2 * r + 1, r};
            SDL_RenderSetClipRect(m_renderer, &box);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 2:{
            SDL_Rect box = {x - r, y, 2 * r + 1, r+1};
            SDL_RenderSetClipRect(m_renderer, &box);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        default: break;
    }

}
void aaQuarter_circle(SDL_Renderer * m_renderer, int x, int y, int r, int red, int green, int blue, int alpha, int position){
    switch (position) {
        case 1:{
            SDL_Rect box = {x, y - r, r + 1, r};
            SDL_RenderSetClipRect(m_renderer, &box);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 2:{
            SDL_Rect box = {x-r, y - r, r + 1, r};
            SDL_RenderSetClipRect(m_renderer, &box);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 3:{
            SDL_Rect box = {x, y, r + 1, r+1};
            SDL_RenderSetClipRect(m_renderer, &box);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        case 4:{
            SDL_Rect box = {x-r, y, r + 1, r+1};
            SDL_RenderSetClipRect(m_renderer, &box);
            aacircleRGBA(m_renderer, x, y, r, red, green, blue, alpha);
            SDL_RenderSetClipRect(m_renderer, nullptr);
        } break;
        default: break;
    }
}
void aaFilledCircleRGBA(SDL_Renderer * m_renderer, int x, int y, int r, int red, int green, int blue, int alpha){
    filledCircleRGBA( m_renderer, x, y, r, red, green, blue, alpha);
    aacircleRGBA( m_renderer, x, y, r, red, green, blue, alpha);
}
void aaFilledCircleRGBA_3D(SDL_Renderer * m_renderer, int x, int y, int r, int red, int green, int blue, int alpha){
    int border_red = border(red), border_green = border(green), border_blue = border(blue);
    int shadow_red = shadow(red), shadow_green = shadow(green), shadow_blue = shadow(blue);
    aaFilledCircleRGBA( m_renderer, x, y+2, r, shadow_red, shadow_green, shadow_blue, alpha);
    aaFilledCircleRGBA( m_renderer, x, y, r+1, border_red, border_green, border_blue, alpha);
    aaFilledCircleRGBA( m_renderer, x, y, r, red, green, blue, alpha);
}
//shapes
//great adjustment: alpha does matter now for all the shape functions. !!! although it is not complete yet. alright now it is completed but not fully.
void curvey_rect(SDL_Renderer * m_renderer, int x, int y, int w, int h, int r,  int red, int green, int blue, int alpha){
    SDL_Rect lower_rect = {x, y+r, w, h-r};
    SDL_Rect upper_rect = {x+r, y, w-2*r, r};
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    SDL_RenderFillRect(m_renderer, &lower_rect);
    SDL_RenderFillRect(m_renderer, &upper_rect);
    aaFilledQuarter_circle(m_renderer, x+r, y+r, r, red, green, blue, alpha, 2);
    aaFilledQuarter_circle(m_renderer, x+w-r-1, y+r, r, red, green, blue, alpha, 1);
}
void curvey_rect_3D(SDL_Renderer * m_renderer, int x, int y, int w, int h, int r,  int red, int green, int blue, int alpha){
    int border_red = border(red), border_green = border(green), border_blue = border(blue);
    int shadow_red = shadow(red), shadow_green = shadow(green), shadow_blue = shadow(blue);
    curvey_rect(m_renderer, x-3, y+3, w, h, r, shadow_red, shadow_green, shadow_blue, alpha);
    curvey_rect(m_renderer, x-1, y+1, w, h, r, border_red, border_green, border_blue, alpha);
    curvey_rect(m_renderer, x, y, w, h, r, red, green, blue, alpha);
    //testing for outline... relative success.
    aaQuarter_circle(m_renderer, x+r, y+r, r, 0, 0, 0, alpha, 2);
    aaQuarter_circle(m_renderer, x+w-r-1, y+r, r, 0, 0, 0, alpha, 1);
    vlineRGBA(m_renderer, x, y+r, y+h, 0, 0, 0, 255);
    vlineRGBA(m_renderer, x+w-1, y+r, y+h, 0, 0, 0, 255);
    hlineRGBA(m_renderer, x+r, x+w-r, y, 0, 0, 0, 255);
    hlineRGBA(m_renderer, x, x+w, y+h, 0, 0, 0, 255);
}
void complete_curvey_rect(SDL_Renderer * m_renderer, int x, int y, int w, int h, int r,  int red, int green, int blue, int alpha){
    SDL_Rect middle_rect = {x, y+r, w, h-2 * r};
    SDL_Rect upper_rect = {x+r+1, y, w-2*r-2, r};
    SDL_Rect lower_rect = {x+r+1, y+h-r, w-2*r-2, r+1};
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    SDL_RenderFillRect(m_renderer, &lower_rect);
    SDL_RenderFillRect(m_renderer, &upper_rect);
    SDL_RenderFillRect(m_renderer, &middle_rect);
    aaFilledQuarter_circle(m_renderer, x+r, y+r, r, red, green, blue, alpha, 2);
    aaFilledQuarter_circle(m_renderer, x+w-r-1, y+r, r, red, green, blue, alpha, 1);
    aaFilledQuarter_circle(m_renderer, x+w-r-1, y+h-r, r, red, green, blue, alpha, 3);
    aaFilledQuarter_circle(m_renderer, x+r, y+h-r, r, red, green, blue, alpha, 4);
}
void complete_curvey_rect_3D(SDL_Renderer * m_renderer, int x, int y, int w, int h, int r,  int red, int green, int blue, int alpha){
    int border_red = border(red), border_green = border(green), border_blue = border(blue);
    int shadow_red = shadow(red), shadow_green = shadow(green), shadow_blue = shadow(blue);
    complete_curvey_rect(m_renderer, x-2, y+2, w, h, r, shadow_red, shadow_green, shadow_blue, alpha);
    complete_curvey_rect(m_renderer, x-1, y-1, w, h, r, border_red, border_green, border_blue, alpha);
    complete_curvey_rect(m_renderer, x, y, w, h, r, red, green, blue, alpha);
}

//shape defining and struct associated with it.

bool PointInCircle(const SDL_Point* point, const Circle* c){
    if(point and c){
        int dx = point->x - c->x;
        int dy = point->y - c->y;
        return dx*dx - dy*dy <= c->r*c->r;
    }
    return false;
}
bool PointInCurveyRect (const SDL_Point* point, const CurveyRect* rect){
    if(point and rect){
        bool inRadius = true;
        if(point->x >= rect->x and point->x <= rect->x + rect->w and point->y >= rect->y and point->y <= rect->y + rect->h){

            if(point->x <= rect->r + rect->x and point->y <= rect->y + rect->r){
                int dx = point->x - (rect->r + rect->x), dy = point->y - (rect->r + rect->y);
                inRadius = (dx*dx + dy*dy <= rect->r*rect->r);
            }
            else if(point->x >= rect->x + rect->w - rect->r and point->y <= rect->y + rect->r){
                int dx = point->x - (rect->x + rect->w - rect->r), dy = point->y - (rect->r + rect->y);
                inRadius = (dx*dx + dy*dy <= rect->r*rect->r);
            }
            return inRadius;
        }
        return false;
    }
    return false;
}
bool PointInCompleteCurveyRect (const SDL_Point* point, const CompleteCurveyRect* rect){
    if(point and rect){
        bool inRadius = true;
        if(point->x >= rect->x and point->x <= rect->x + rect->w and point->y >= rect->y and point->y <= rect->y + rect->h){

            if(point->x <= rect->r + rect->x and point->y <= rect->y + rect->r){
                int dx = point->x - (rect->r + rect->x), dy = point->y - (rect->r + rect->y);
                inRadius = (dx*dx + dy*dy <= rect->r*rect->r);
            }
            else if(point->x >= rect->x + rect->w - rect->r and point->y <= rect->y + rect->r){
                int dx = point->x - (rect->x + rect->w - rect->r), dy = point->y - (rect->r + rect->y);
                inRadius = (dx*dx + dy*dy <= rect->r*rect->r);
            }
            else if(point->x <= rect->r + rect->x and point->y >= rect->y + rect->h - rect->r){
                int dx = point->x - (rect->r + rect->x), dy = point->y - (rect->y + rect->h - rect->r);
                inRadius = (dx*dx + dy*dy <= rect->r*rect->r);
            }
            else if(point->x >= rect->x + rect->w - rect->r and point->y >= rect->y + rect->h - rect->r){
                int dx = point->x - (rect->x + rect->w - rect->r), dy = point->y - (rect->y + rect->h - rect->r);
                inRadius = (dx*dx + dy*dy <= rect->r*rect->r);
            }
            return inRadius;
        }
        return false;
    }
    return false;


}
void ribbonButtonCircle(SDL_Renderer * m_renderer, Sint16 x, Sint16 y, Sint16 r, Uint8 R, Uint8 G, Uint8 B, Uint8 A){
    filledCircleRGBA( m_renderer, x, y, r, R, G, B, A);
    aacircleRGBA( m_renderer, x, y, r, 0, 0, 0, 255);
}
void aaInscribedPolygon(SDL_Renderer * m_renderer, Sint16 x, Sint16 y, Sint16 r, int n, Uint8 R, Uint8 G, Uint8 B, Uint8 A){
    vector<Sint16> X(n);
    vector<Sint16> Y(n);
    for(int i=0; i<n; i++){
        X[i] = x - r * cos((2 * M_PI * i) / n);
        Y[i] = y - r * sin((2 * M_PI * i) / n);
    }

    filledPolygonRGBA(m_renderer, X.data(), Y.data(), n, R, G, B, A);
    aapolygonRGBA(m_renderer, X.data(), Y.data(), n, R, G, B, A);
}
void ribbonButtonPolygon(SDL_Renderer * m_renderer, vector<Sint16> X, vector<Sint16> Y, Uint8 R, Uint8 G, Uint8 B, Uint8 A){
    filledPolygonRGBA(m_renderer, X.data(), Y.data(), 6, R, G, B, A);
    aapolygonRGBA(m_renderer, X.data(), Y.data(), 6, 0, 0, 0, 255);
}
bool pointInPolygon(int n, const Sint16* X, const Sint16* Y, Sint16 x, Sint16 y){
    bool inside = false;
    for(int i=0, j=n-1; i<n; j=i++){
        if( ((Y[i]>y) != (Y[j] > y)) and (x < (float)(X[j]-X[i]) * (y-Y[i]) / (Y[j] - Y[i]) + X[i]) ){
            inside = !inside;
        }
    }
    return inside;
}
bool pointInRibbonButton(const SDL_Point* point, const RibbonButton* button){
    return pointInPolygon(6, button-> X.data(), button-> Y.data(), (Sint16 )point->x, (Sint16 )point->y);
}
//void aaRoundedRect(SDL_Renderer * m_renderer, int x, int y, int r, int w, int h, SDL_Color color){
//    roundedBoxRGBA(m_renderer, x, y, x+w, x+h, r, color.r, color.g, color.b, color.a);
//    aaQuarter_circle(m_renderer, x+r, y+r, r, color.r, color.g, color.b, color.b, 2);
//    aaQuarter_circle(m_renderer, x+w-r-1, y+r, r, color.r, color.g, color.b, color.a, 1);
//    aaQuarter_circle(m_renderer, x+w-r-1, y+h-r, r, color.r, color.g, color.b, color.r, 3);
//    aaQuarter_circle(m_renderer, x+r, y+h-r, r, color.r, color.g, color.b, color.a, 4);
//
//
//}



void drawBlock1(SDL_Renderer *m_renderer, block1& block){
    int x = block.x, y = block.y, h = block.h, w = block.w;
    int R = block.color.r, G = block.color.g, B = block.color.b, A = block.color.a;
    int temp = int(h/(2 * sqrt(3)));
    vector<Sint16> x1 = {(Sint16)x, (Sint16)(x-temp), (Sint16)x};
    vector<Sint16> y1 = {(Sint16)y, (Sint16)(y+h/2) , (Sint16)(y+h)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    int inc1 = h/3;
    SDL_Rect rect1 = {x, y, inc1, h+1};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);
    x1 = {(Sint16)(x+h/3), (Sint16)(x+h/3 + h/6), (Sint16)(x+h/3+h/6), (Sint16)(x+inc1)};
    y1 = {(Sint16)(y), (Sint16)(y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    rect1 = {x+h/3+h/6, int(y+(h*sqrt(3) / 6))+1, h/3+1, h};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);

    x1 = {(Sint16)(x+ h/3 + 2 * h / 3), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3)};
    y1 = {(Sint16)(y), (Sint16)(y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    double wFinal = w - h * (1 + (1 / sqrt(3)));

    rect1 = {x + h, y, int(wFinal), h};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);

    x1 = {(Sint16)(x + h + wFinal), (Sint16)(x+h+wFinal+temp), (Sint16)(x + h + wFinal)};
    y1 = {(Sint16)y, (Sint16)(y+h/2) , (Sint16)(y+h)};

    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    SDL_Surface* b_surf = TTF_RenderText_Blended(block.font, block.opCode.c_str(), black);
    SDL_Texture* b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    int helpY = (int)(((y+(h*sqrt(3) / 6)) + (y + h))/2 - b_surf->h / 2.0);
    int helpX = (int)(x+h/3);
    SDL_Rect b_text_rect = {helpX, helpY, b_surf->w, b_surf->h};

    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);

    block.text_box1 = {b_text_rect.x + b_text_rect.w + h/6, y + (h/4), b_text_rect.w, h/2};
    block.text_box2 = {block.text_box1.x+block.text_box1.w+h/6, y + (h/4), b_text_rect.w, h/2};





    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    if(!block.input1.empty()){ SDL_RenderFillRect(m_renderer, &block.text_box1); }
    if(!block.input2.empty()){ SDL_RenderFillRect(m_renderer, &block.text_box2); }







    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
}



//void renderBlock1(SDL_Renderer * m_renderer, block1 &b, TTF_Font* font{
//}
void drawBlock2 (SDL_Renderer *m_renderer, const block2& block){
    int x = block.x, y = block.y, h = block.h, w = block.w;
    int R = block.color.r, G = block.color.g, B = block.color.b, A = block.color.a;
    vector<Sint16> x1 = {(Sint16)(x+h/3), (Sint16)(x+h/3+h/6), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3)};
    vector<Sint16> y1 = {(Sint16)(h+y), (Sint16)(h+y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    SDL_Rect rect1 = {x, y, int(w - h/(sqrt(3))), h};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);
    int temp = int(h/(2 * sqrt(3)));
    x1 = {(Sint16)x, (Sint16)(x-temp), (Sint16)x};
    y1 = {(Sint16)y, (Sint16)(y+h/2) , (Sint16)(y+h)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);

    double wFinal = w - h * (1 + (1 / sqrt(3)));

    x1 = {(Sint16)(x + h + wFinal), (Sint16)(x+h+wFinal+temp), (Sint16)(x + h + wFinal)};
    y1 = {(Sint16)y, (Sint16)(y+h/2) , (Sint16)(y+h)};

    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    vector<Sint16 > x2;
    vector<Sint16> y2;
    x2 = {Sint16(x), Sint16(x+h/2.0), Sint16(x+h), Sint16(x+3*h/2.0), Sint16(x + 2.0 * h)};
    y2 = {Sint16(y), Sint16(y-h/3.0), Sint16(y-h/2.0), Sint16(y-h/3.0), Sint16(y)};
    filledPolygonRGBA(m_renderer, x2.data(), y2.data(), 5, R, G, B, A);
    aapolygonRGBA(m_renderer, x2.data(), y2.data(), 5, R, G, B, A);



}

#endif //GITTESTT_SHAPES_H