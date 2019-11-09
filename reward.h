#ifndef REWARD_H
#define REWARD_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>

class Reward : public sf::Drawable
{
public:
    Reward();

    int getId() const;

    sf::Sprite getSprite() const;

    void setPosition(sf::Vector2f pos);
    void destroy();
    void generateId();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int id;
    int size;
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif // REWARD_H
