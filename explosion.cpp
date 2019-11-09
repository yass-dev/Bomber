#include "explosion.h"

Explosion::Explosion(sf::Vector2f pos)
{
    texture.loadFromFile("explosion.png");
    sprite.setTexture(texture);
    sprite.setPosition(pos);
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(timer.getElapsedTime().asSeconds() < 2)
    {
        target.draw(sprite);
    }
}


sf::Vector2f Explosion::getPosition() const
{
    return sprite.getPosition();
}
