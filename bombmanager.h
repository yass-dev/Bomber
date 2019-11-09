#ifndef BOMBMANAGER_H
#define BOMBMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bomb.h"
#include "map.h"
#include "player.h"
#include "reward.h"
#include "explosion.h"

class BombManager: public sf::Drawable
{
public:
    BombManager(Player *pl);

    enum Dir{Up, Right, Down, Left, Null};

    void addBomb(sf::Vector2f pos);
    void update(sf::Vector2f pos, unsigned int fire, unsigned int mapwidth, unsigned int blockSize, Map *map);
    void exploseBomb(unsigned int i, bool fromAnotherBomb, Dir direction);

    std::vector<Bomb*> getBombs() const;
    std::vector<Reward*> getRewards() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<Bomb*> vecBomb;
    std::vector<Reward*> vecReward;
    std::vector<Explosion*> vecExplosion;
    unsigned int playerFire;
    unsigned int mapWidth;
    unsigned int blockSize;
    bool canContinueRight, canContinueUp, canContinueDown, canContinueLeft;
    bool canConinueExplose;

    sf::Texture texture;

    Map *map;
    Player *player;
};

#endif // BOMBMANAGER_H
