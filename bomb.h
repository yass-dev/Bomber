#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>

class Bomb : public sf::Drawable
{
public:
    Bomb(sf::Vector2f pos);

    bool isExplosed();

    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void destroy();

    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock time;

    bool isDestroyed;

    unsigned int explosedTime;
};

#endif // BOMB_H
