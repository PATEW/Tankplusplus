#ifndef TANKPLUSPLUS_BLOCKGENERATOR_H
#define TANKPLUSPLUS_BLOCKGENERATOR_H

#include "raylib.h"
#include "Block.h"
#include <vector>

class BlockGenerator {
private:
    std::vector<Block> blocksVec;
public:
    std::vector<Block> createLevel(int levelNum, Vector2 input_screenDimensions);
};


#endif //TANKPLUSPLUS_BLOCKGENERATOR_H
