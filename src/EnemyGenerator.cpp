#include "EnemyGenerator.h"

// master list of enemy locations
std::vector<Enemy>* EnemyGenerator::createEnemies(int levelNum, Vector2 input_screenDimensions) {

    std::vector<Enemy>* enemiesVecPtr = new std::vector<Enemy>();


    switch (levelNum) {
        case 1: {
            enemiesVecPtr->clear();

            //enemy 0
            Enemy enemy((input_screenDimensions.x / 8), (input_screenDimensions.y / 6), BLUE, 50);
            enemiesVecPtr->push_back(enemy);

            //enemy 1
            Enemy enemy1((input_screenDimensions.x / 6), (input_screenDimensions.y / 3), BLACK, 50);
            enemiesVecPtr->push_back(enemy1);

            break;
        }
        default: {
            enemiesVecPtr->clear();
            break;
        }
    }

    return enemiesVecPtr;
}