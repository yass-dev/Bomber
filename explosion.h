#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>

class Explosion : public sf::Drawable
{
public:
    Explosion(sf::Vector2f pos);

    sf::Vector2f getPosition() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock timer;
};

#endif // EXPLOSION_H
