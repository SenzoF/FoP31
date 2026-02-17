//
// Created by ALI on 17/02/2026.
//

#ifndef GITTESTT_BLOCKARRANGEMENT_H
#define GITTESTT_BLOCKARRANGEMENT_H

#include "Essentials.h"
#include "Shapes.h"
//motion blocks making
int size_motion = 15;
vector<block1> menu_block_motion(size_motion);

int size_looks = 17;
vector<block1> menu_block_looks(size_looks);









void arrange(int dist, vector<block1> &blocks){
    for(int i=1; i<blocks.size(); i++){
        blocks[i].y = blocks[i-1].y + dist;
    }
}
#endif //GITTESTT_BLOCKARRANGEMENT_H
