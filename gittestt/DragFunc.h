

#ifndef GITTESTT_DRAGFUNC_H
#define GITTESTT_DRAGFUNC_H

#include "Essentials.h"
#include "Shapes.h"

static bool dragging = false;
static int drag_x = 0;
static int drag_y = 0;

bool mouseIsInside (const block1& block1 , int x , int y) {
    return((x>= block1.x) && (x<= block1.x + block1.w) && (y>= block1.y) && (y<= block1.y + block1.h));
}
bool mouseIsInside2 (vector<block1> &block1 , int x , int y , int i) {
    return((x>= block1[i].x) && (x<= block1[i].x + block1[i].w) && (y>= block1[i].y) && (y<= block1[i].y + block1[i].h));
}

static void drag1(SDL_Event& e,block1 & block1) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            int mouseX = e.button.x;
            int mouseY = e.button.y;

            if (mouseIsInside(block1, mouseX, mouseY)) {
                dragging = true;
                drag_x = mouseX-block1.x;
                drag_y = mouseY-block1.y;

            }
        }
        if (e.type == SDL_MOUSEBUTTONUP) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                dragging = false;
            }
        }
        if (e.type == SDL_MOUSEMOTION) {
            if (dragging) {
                block1.x = e.motion.x-drag_x;
                block1.y = e.motion.y-drag_y;
            }
        }
    }
}



static bool IsNeighbor1(const block1& block_1 , const block1& block_2) {
    if ((abs(block_2.x - block_1.x) < block_1.w/2 +20)&&(abs(block_1.y-block_2.y ) < block_1.h+20)) {
        return true;
    }
    else return false;
}

static void magnetup(const block1& block_1 ,  block1 &block_2) {
    if ((IsNeighbor1(block_1,block_2))&&(block_2.y < block_1.y)) {
        block_2.x = block_1.x;
        block_2.y = block_1.y - block_1.h;
    }
}

static void magnetdown(const block1& block_1 ,  block1 &block_2) {
    if ((IsNeighbor1(block_1,block_2))&&(block_2.y > block_1.y)) {
        block_2.x = block_1.x;
        block_2.y = block_1.y + block_1.h;
    }
}

void arrangeprogram(vector <block1>& program)
{
    if (program.empty())
    {
        return;
    }
    program[0].x=550;
    program[0].y=200;

    for (int i = 1; i < program.size(); i++)
    {
        program[i].x=program[i-1].x;
        program[i].y=program[i-1].y+program[i-1].h;
    }

}

bool checkMagnet1(block1& dragged, block1& target)
{
    int dx1 = abs(target.topSnap.x - dragged.bottomSnap.x);
    int dy1 = abs(target.topSnap.y - dragged.bottomSnap.y);

    int dx2 = abs(target.topSnap.x - dragged.bottomSnap.x);
    int dy2 = abs(target.topSnap.y+target.w - dragged.bottomSnap.y);

    return((dx1<25 && dy1<15)||(dx2<25 && dy2<15));
}


#endif //GITTESTT_DRAGFUNC_H

