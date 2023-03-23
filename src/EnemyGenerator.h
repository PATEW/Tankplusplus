#ifndef TANKPLUSPLUS_ENEMYGENERATOR_H
#define TANKPLUSPLUS_ENEMYGENERATOR_H

#include "raylib.h"
#include "Enemy.h"
#include <vector>

class EnemyGenerator {
public:
    static std::vector<Enemy>* createEnemies(int levelNum, Vector2 input_screenDimensions);
};



#endif //TANKPLUSPLUS_ENEMYGENERATOR_H
