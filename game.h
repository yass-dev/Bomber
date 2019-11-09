#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "player.h"
#include "map.h"
#include "collisionmanager.h"
#include "bombmanager.h"

class Game
{
public:
    Game();

    void run();

private:
    void checkCollision();
    sf::RenderWindow window;
    sf::View view;

    Player player;
    Map map;
    CollisionManager collisionManager;
    BombManager bombManager;

    int exCurrent, exAbove, exBelow, exRight, exLeft;
    unsigned int highCurrentBlock, currentBlock, lowCurrentBlock;
    int highAboveBlock, aboveBlock, lowAboveBlock, highBelowBlock, belowBlock, lowBelowBlock, highRightBlock, rightBlock, lowRightBlock, highLeftBlock, leftBlock, lowLeftBlock;
};

#endif // GAME_H
