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








void arrange(int dist, vector<block1> &blocks){
    for(int i=1; i<blocks.size(); i++){
        blocks[i].y = blocks[i-1].y + dist;
    }
}
#endif //FOP_PROJECT_ALI_BLOCKARRANGEMENT_H
