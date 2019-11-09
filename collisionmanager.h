#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "block.h"
#include "bomb.h"

class CollisionManager
{
public:
    CollisionManager();

    bool isCollision(Player *player, Block *block);
    bool isCollision(Player *player, Reward *reward);
    bool isCollision(Player *player, Bomb *bomb);
};

#endif // COLLISIONMANAGER_H
