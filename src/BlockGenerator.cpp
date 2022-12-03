#include "BlockGenerator.h"

// master list of block locations
std::vector<Block> BlockGenerator::createLevel(int levelNum, Vector2 input_screenDimensions) {

    switch (levelNum) {
        case 1: {
            blocksVec.clear();

            Block block((input_screenDimensions.x / 4 * 3), (input_screenDimensions.y / 2), 100, 100, BLUE);
            blocksVec.push_back(block);

            Block block1((input_screenDimensions.x / 4 * 1), (input_screenDimensions.y / 3), 100, 100, RED);
            blocksVec.push_back(block1);

            break;
        }
        default: {
            blocksVec.clear();
            break;
        }
    }

    return blocksVec;
}
