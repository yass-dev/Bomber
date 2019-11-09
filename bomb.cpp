#include "bomb.h"

Bomb::Bomb(sf::Vector2f pos)
    :isDestroyed(false), explosedTime(5)
{
    texture.loadFromFile("bomb.png");
    sprite.setTexture(texture);
    texture.setSmooth(true);

    sprite.setPosition(pos);
    time.restart();
}

void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(!isDestroyed)
        target.draw(sprite);
}

bool Bomb::isExplosed()
{
    if(time.getElapsedTime().asSeconds() >= explosedTime)
    {
        return true;
    }
    else
        return false;
}

void Bomb::destroy()
{
    isDestroyed = true;
    sprite.setPosition(10000, 10000);
}

sf::Vector2f Bomb::getPosition() const
{
    return sprite.getPosition();
}

sf::Sprite Bomb::getSprite() const
{
    return sprite;
}
