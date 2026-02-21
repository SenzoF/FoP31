//
// Created by ALI on 16/02/2026.
//

#ifndef FOP_PROJECT_ALI_SHAPES_H
#define FOP_PROJECT_ALI_SHAPES_H

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
    int x, y, w=100, h;
    SDL_Color color;
    string input1 = "10";
    string input2=" ";

    bool isFocused1 = false;
    bool isFocused2 = false;
    string opCode;
    TTF_Font *font;
    SDL_Rect text_box1;
    SDL_Rect text_box2;
    SDL_Color text_box_normalC = light_gray;
    SDL_Color text_box_focusedC = white;

    bool isdrag=false;

    SDL_Point topSnap;
    SDL_Point bottomSnap;
};
struct block2 {
    int x, y, w, h;
    SDL_Color color;
    string input;
    vector<SDL_Rect> box;
};


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




void drawBlock1(SDL_Renderer *m_renderer, block1& block){
    int x = block.x, y = block.y, h = block.h, w = block.w;
    int R = block.color.r, G = block.color.g, B = block.color.b, A = block.color.a;
    vector<Sint16> x1 = {(Sint16)x, (Sint16)(x-h/(2 * sqrt(3))), (Sint16)x};
    vector<Sint16> y1 = {(Sint16)y, (Sint16)(y+h/2) , (Sint16)(y+h)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    SDL_Rect rect1 = {x, y, h/3, h+1};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);
    x1 = {(Sint16)(x+h/3), (Sint16)(x+h/3 + h/6), (Sint16)(x+h/3+h/6), (Sint16)(x+(h/3))};
    y1 = {(Sint16)(y), (Sint16)(y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    rect1 = {x+h/3+h/6, int(y+(h*sqrt(3) / 6))+1, h/3+2, h};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);
    x1 = {(Sint16)(x+ h/3 + 2 * h / 3), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3)};
    y1 = {(Sint16)(y), (Sint16)(y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);

    //for opCode writing on the block.
    SDL_Surface* b_surf = TTF_RenderText_Blended(block.font, block.opCode.c_str(), black);
    SDL_Texture* b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    int helpY = (int)(((y+(h*sqrt(3) / 6)) + (y + h))/2 - b_surf->h / 2.0);
    int helpX = (int)(x+h/3);
    SDL_Rect b_text_rect = {helpX, helpY, b_surf->w, b_surf->h};

    string textToRender1 = block.input1;
    if(textToRender1.empty()){
        textToRender1 = " ";
    }
    string textToRender2 = block.input2;
    if(textToRender1.empty()){
        textToRender2 = " ";
    }

    // for the first rectangle
    SDL_Surface* text_box1_surf = TTF_RenderText_Blended(block.font, textToRender1.c_str(), black);
    SDL_Texture* text_box1_tex = SDL_CreateTextureFromSurface(m_renderer, text_box1_surf);
    SDL_Rect text_box1_rect = {helpX + b_text_rect.w +h/6, block.y + block.h /2 - text_box1_surf->h/2, text_box1_surf->w, text_box1_surf->h};
    //for the second rectangle
    SDL_Surface* text_box2_surf = TTF_RenderText_Blended(block.font, textToRender2.c_str(), black);
    SDL_Texture* text_box2_tex = SDL_CreateTextureFromSurface(m_renderer, text_box2_surf);
    SDL_Rect text_box2_rect = {text_box1_rect.x + text_box1_rect.w +h/6, block.y + block.h /2 - text_box2_surf->h/2, text_box2_surf->w, text_box2_surf->h};
    //for the final rect.
    rect1 = {x + h, y, text_box2_rect.x + text_box2_rect.w - (x+h) + 2 * h/6 , h+1};

    //the final polygon
    x1 = {(Sint16)(rect1.x + rect1.w), (Sint16)(h / (2 * sqrt(3)) + rect1.x + rect1.w), (Sint16)(rect1.x + rect1.w)};
    y1 = {(Sint16)(y), (Sint16)(y+h/2) , (Sint16)(y+h)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);

    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);

    if(block.isFocused1)SDL_SetRenderDrawColor(m_renderer, block.text_box_focusedC.r, block.text_box_focusedC.g, block.text_box_focusedC.b, block.text_box_focusedC.a);
    else SDL_SetRenderDrawColor(m_renderer, block.text_box_normalC.r, block.text_box_normalC.g, block.text_box_normalC.b, block.text_box_normalC.a);
    if(!(block.input1==" "))SDL_RenderFillRect(m_renderer, &block.text_box1);

    if(block.isFocused2)SDL_SetRenderDrawColor(m_renderer, block.text_box_focusedC.r, block.text_box_focusedC.g, block.text_box_focusedC.b, block.text_box_focusedC.a);
    else SDL_SetRenderDrawColor(m_renderer, block.text_box_normalC.r, block.text_box_normalC.g, block.text_box_normalC.b, block.text_box_normalC.a);
    if(!(block.input2==" "))SDL_RenderFillRect(m_renderer, &block.text_box2);

    block.w = int (abs( x - (rect1.x + rect1.w) ));
    block.text_box1 = {text_box1_rect.x, text_box1_rect.y, text_box1_rect.w + 3, text_box1_rect.h};
    block.text_box2 = {text_box2_rect.x, text_box2_rect.y, text_box2_rect.w + 3, text_box2_rect.h};



    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);

    if(!(block.input1==" "))SDL_RenderCopy(m_renderer, text_box1_tex, nullptr, &text_box1_rect);

    if(!(block.input2==" "))SDL_RenderCopy(m_renderer, text_box2_tex, nullptr, &text_box2_rect);

    //setting the width here.


    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
    SDL_FreeSurface(text_box1_surf);
    SDL_DestroyTexture(text_box1_tex);
    SDL_FreeSurface(text_box2_surf);
    SDL_DestroyTexture(text_box2_tex);
}



void drawBlock2 (SDL_Renderer *m_renderer, block1& block){
    int x = block.x, y = block.y, h = block.h, w = block.w;
    int R = block.color.r, G = block.color.g, B = block.color.b, A = block.color.a;
    vector<Sint16> x1 = {(Sint16)x, (Sint16)(x-h/(2 * sqrt(3))), (Sint16)x};
    vector<Sint16> y1 = {(Sint16)y, (Sint16)(y+h/2) , (Sint16)(y+h)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    SDL_Rect rect1 = {x, y, h/3, h+1};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);
    x1 = {(Sint16)(x+h/3), (Sint16)(x+h/3 + h/6), (Sint16)(x+h/3+h/6), (Sint16)(x+(h/3))};
    y1 = {(Sint16)(y), (Sint16)(y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    rect1 = {x+h/3+h/6, int(y+(h*sqrt(3) / 6))+1, h/3+2, h};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);
    x1 = {(Sint16)(x+ h/3 + 2 * h / 3), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3 - h/6), (Sint16)(x+ h/3 + 2 * h / 3)};
    y1 = {(Sint16)(y), (Sint16)(y+(h*sqrt(3) / 6)) , (Sint16)(h+y+(h*sqrt(3) / 6)), (Sint16)(h+y)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 4, R, G, B, A);

    //for opCode writing on the block.
    SDL_Surface* b_surf = TTF_RenderText_Blended(block.font, block.opCode.c_str(), black);
    SDL_Texture* b_tex = SDL_CreateTextureFromSurface(m_renderer, b_surf);
    int helpY = (int)(((y+(h*sqrt(3) / 6)) + (y + h))/2 - b_surf->h / 2.0);
    int helpX = (int)(x+h/3);
    SDL_Rect b_text_rect = {helpX, helpY, b_surf->w, b_surf->h};

    string textToRender1 = block.input1;
    if(textToRender1.empty()){
        textToRender1 = " ";
    }
    string textToRender2 = block.input2;
    if(textToRender1.empty()){
        textToRender2 = " ";
    }

    // for the first rectangle
    SDL_Surface* text_box1_surf = TTF_RenderText_Blended(block.font, textToRender1.c_str(), black);
    SDL_Texture* text_box1_tex = SDL_CreateTextureFromSurface(m_renderer, text_box1_surf);
    SDL_Rect text_box1_rect = {helpX + b_text_rect.w +h/6, block.y + block.h /2 - text_box1_surf->h/2, text_box1_surf->w, text_box1_surf->h};
    //for the second rectangle
    SDL_Surface* text_box2_surf = TTF_RenderText_Blended(block.font, textToRender2.c_str(), black);
    SDL_Texture* text_box2_tex = SDL_CreateTextureFromSurface(m_renderer, text_box2_surf);
    SDL_Rect text_box2_rect = {text_box1_rect.x + text_box1_rect.w +h/6, block.y + block.h /2 - text_box2_surf->h/2, text_box2_surf->w, text_box2_surf->h};
    //for the final rect.
    rect1 = {x + h, y, text_box2_rect.x + text_box2_rect.w - (x+h) + 2 * h/6 , h+1};

    //the final polygon
    x1 = {(Sint16)(rect1.x + rect1.w), (Sint16)(h / (2 * sqrt(3)) + rect1.x + rect1.w), (Sint16)(rect1.x + rect1.w)};
    y1 = {(Sint16)(y), (Sint16)(y+h/2) , (Sint16)(y+h)};
    filledPolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);
    aapolygonRGBA(m_renderer, x1.data(), y1.data(), 3, R, G, B, A);

    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &rect1);

    if(block.isFocused1)SDL_SetRenderDrawColor(m_renderer, block.text_box_focusedC.r, block.text_box_focusedC.g, block.text_box_focusedC.b, block.text_box_focusedC.a);
    else SDL_SetRenderDrawColor(m_renderer, block.text_box_normalC.r, block.text_box_normalC.g, block.text_box_normalC.b, block.text_box_normalC.a);
    if(!(block.input1==" "))SDL_RenderFillRect(m_renderer, &block.text_box1);

    if(block.isFocused2)SDL_SetRenderDrawColor(m_renderer, block.text_box_focusedC.r, block.text_box_focusedC.g, block.text_box_focusedC.b, block.text_box_focusedC.a);
    else SDL_SetRenderDrawColor(m_renderer, block.text_box_normalC.r, block.text_box_normalC.g, block.text_box_normalC.b, block.text_box_normalC.a);
    if(!(block.input2==" "))SDL_RenderFillRect(m_renderer, &block.text_box2);

    block.w = int (abs( x - (rect1.x + rect1.w) ));
    block.text_box1 = {text_box1_rect.x, text_box1_rect.y, text_box1_rect.w + 3, text_box1_rect.h};
    block.text_box2 = {text_box2_rect.x, text_box2_rect.y, text_box2_rect.w + 3, text_box2_rect.h};



    SDL_RenderCopy(m_renderer, b_tex, nullptr, &b_text_rect);

    if(!(block.input1==" "))SDL_RenderCopy(m_renderer, text_box1_tex, nullptr, &text_box1_rect);

    if(!(block.input2==" "))SDL_RenderCopy(m_renderer, text_box2_tex, nullptr, &text_box2_rect);

    //setting the width here.


    SDL_FreeSurface(b_surf);
    SDL_DestroyTexture(b_tex);
    SDL_FreeSurface(text_box1_surf);
    SDL_DestroyTexture(text_box1_tex);
    SDL_FreeSurface(text_box2_surf);
    SDL_DestroyTexture(text_box2_tex);

    //adding polygons and rects to change it.
    vector<Sint16> x2, y2;
    x2 = {Sint16(x), Sint16(x+h/2.0), Sint16(x+h), Sint16(x+3*h/2.0), Sint16(x + 2.0 * h)};
    y2 = {Sint16(y), Sint16(y-h/3.0), Sint16(y-h/2.0), Sint16(y-h/3.0), Sint16(y)};
    filledPolygonRGBA(m_renderer, x2.data(), y2.data(), 5, R, G, B, A);
    aapolygonRGBA(m_renderer, x2.data(), y2.data(), 5, R, G, B, A);
    SDL_Rect final_touch = {x + h/3, y+1,  2 * h / 3, int(  h / 2 / (sqrt(3)) + 2 )};
    SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
    SDL_RenderFillRect(m_renderer, &final_touch);

}


bool pointInBlock1(const SDL_Point* point, const block1* block){
    if(point->x >= block->x and point ->x <= (block->x + block->w) and point->y >= block->y and point ->y <= (block->y + block->h)){
        if(!(SDL_PointInRect(point, &block->text_box1) or SDL_PointInRect(point, &block->text_box2)))return true;
    }
    return false;
}








#endif //FOP_PROJECT_ALI_SHAPES_H