#include "reward.h"

Reward::Reward()
{

}

void Reward::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}

int Reward::getId() const
{
    return id;
}

void Reward::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

sf::Sprite Reward::getSprite() const
{
    return sprite;
}

void Reward::destroy()
{
    sprite.setPosition(10000, 10000);
}

void Reward::generateId()
{
    srand(time(nullptr));
    id = std::rand()%3 + 0;
    std::cout << "id = " << id <<std::endl;

    if(id == 0)
    {
        texture.loadFromFile("flammeReward.png");
    }
    else if(id == 1)
    {
        texture.loadFromFile("speed.png");
    }
    else if(id == 2)
    {
        texture.loadFromFile("bomb.png");
    }
    sprite.setTexture(texture);
}
