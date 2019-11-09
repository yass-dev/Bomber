#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "reward.h"

class Block : public sf::Drawable
{
public:
    Block();
    Block(int typ, sf::Vector2i pos);
    Block(int typ, sf::Vector2f pos);

    void setPosition(sf::Vector2i pos);
    void setPosition(sf::Vector2f pos);
    void changeTexture();
    void destroy();
    void setActive(bool on);

    sf::Sprite getSprite() const;

    sf::Vector2f getPosition() const;

    unsigned int getBlockSize() const;
    unsigned int getType() const;

    bool isBlocker() const;
    bool isBreakable() const;
    bool isActive() const;

    Reward *getReward();

    enum Type {BREAKABLE, INDESTRUCTIBLE, GRASS, GRASS_FONCED};

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2i position;
    bool canBeDestroyed = false;
    bool active;
    unsigned int type;

    Reward reward;
};

#endif // BLOCK_H
