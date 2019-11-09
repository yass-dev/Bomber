#include "block.h"

Block::Block()
{
    sprite.setPosition(position.x, position.y);
    sprite.setTexture(texture);
    texture.setSmooth(true);
}

Block::Block(int typ, sf::Vector2i pos)
{
    position = pos;
    type = typ;
    if(type == BREAKABLE)
    {
        if(!texture.loadFromFile("breakableBlock-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "breakableblock bien charge !" <<std::endl;
        canBeDestroyed = true;
    }
    else if(type == INDESTRUCTIBLE)
    {
        if(!texture.loadFromFile("stone-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "indestructibleblock bien charge !" <<std::endl;
        canBeDestroyed = false;
    }
    else if(type == GRASS)
    {
        if(!texture.loadFromFile("grass_clair-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "Clair grass bien charge !" <<std::endl;
        canBeDestroyed = false;
    }
    else if(type == GRASS_FONCED)
    {
        if(!texture.loadFromFile("grass_fonced-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "Fonced Grass bien charge !" <<std::endl;
        canBeDestroyed = false;
    }
    else
    {
        std::cout << "Type of block unknow" << std::endl;
    }
    sprite.setPosition(position.x, position.y);
    sprite.setTexture(texture);
    texture.setSmooth(true);
}

Block::Block(int typ, sf::Vector2f pos)
{
    position = sf::Vector2i(pos.x, pos.y);
    type = typ;
    if(type == BREAKABLE)
    {
        if(!texture.loadFromFile("breakableBlock-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "breakableblock bien charge !" <<std::endl;
        canBeDestroyed = true;
    }
    else if(type == INDESTRUCTIBLE)
    {
        if(!texture.loadFromFile("stone-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "indestructibleblock bien charge !" <<std::endl;
        canBeDestroyed = false;
    }
    else if(type == GRASS)
    {
        if(!texture.loadFromFile("grass_clair-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "Clair grass bien charge !" <<std::endl;
        canBeDestroyed = false;
    }
    else if(type == GRASS_FONCED)
    {
        if(!texture.loadFromFile("grass_fonced-40.png"))
            std::cout << "error" << std::endl;
        else
            std::cout << "Fonced Grass bien charge !" <<std::endl;
        canBeDestroyed = false;
    }
    else
    {
        std::cout << "Type of block unknow" << std::endl;
    }
    sprite.setPosition(position.x, position.y);
    sprite.setTexture(texture);
    texture.setSmooth(true);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}

void Block::setPosition(sf::Vector2i pos)
{
    position = pos;
    sprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void Block::setPosition(sf::Vector2f pos)
{
    position = sf::Vector2i(pos.x, pos.y);
    sprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

sf::Vector2f Block::getPosition() const
{
    return sf::Vector2f(position.x, position.y);
}

unsigned int Block::getBlockSize() const
{
    return texture.getSize().x;
}

bool Block::isBlocker() const
{
    if(type == INDESTRUCTIBLE || type == BREAKABLE)
        return true;
    else if(type == GRASS_FONCED || type == GRASS)
        return false;
}

sf::Sprite Block::getSprite() const
{
    return sprite;
}

void Block::changeTexture()
{

}

void Block::destroy()
{
    reward.setPosition(sprite.getPosition());
    sprite.setPosition(10000, 10000);
    active = false;
}

Reward *Block::getReward()
{
    return &reward;
}

bool Block::isBreakable() const
{
    return canBeDestroyed;
}

bool Block::isActive() const
{
    return  active;
}

void Block::setActive(bool on)
{
    active = on;
}

unsigned int Block::getType() const
{
    return type;
}
