#include "collisionmanager.h"

CollisionManager::CollisionManager()
{

}

bool CollisionManager::isCollision(Player *player, Block *block)
{
    /*if(player->getDirection() == Player::Up)
    {
        if(player->getSprite().getGlobalBounds().contains(block->getPosition().x, block->getPosition().y + block->getBlockSize())
                || player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize(), block->getPosition().y + block->getBlockSize())
                || player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize()/2, block->getPosition().y + block->getBlockSize()))
            return true;
    }
    else if(player->getDirection() == Player::Right)
    {
        if(player->getSprite().getGlobalBounds().contains(block->getPosition().x, block->getPosition().y)
           || player->getSprite().getGlobalBounds().contains(block->getPosition().x, block->getPosition().y + block->getBlockSize())
           || player->getSprite().getGlobalBounds().contains(block->getPosition().x, block->getPosition().y + block->getBlockSize())/2)
                return true;
    }
    else if(player->getDirection() == Player::Down)
    {
        if(player->getSprite().getGlobalBounds().contains(block->getPosition().x, block->getPosition().y)
           || player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize(), block->getPosition().y)
           || player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize()/2, block->getPosition().y))
        {
            return true;
        }
    }
    else if(player->getDirection() == Player::Left)
    {
        if(player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize(), block->getPosition().y)
           || player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize(), block->getPosition().y + block->getBlockSize())
           || player->getSprite().getGlobalBounds().contains(block->getPosition().x + block->getBlockSize(), block->getPosition().y + block->getBlockSize())/2)
                return true;
    }*/

    if(player->getDirection() == Player::Up)
        {
            if(player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
                    || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
                    || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds()))
                return true;
        }
        else if(player->getDirection() == Player::Right)
        {
            if(player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
               || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
               || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds()))
                    return true;
        }
        else if(player->getDirection() == Player::Down)
        {
            if(player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
               || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
               || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds()))
            {
                return true;
            }
        }
        else if(player->getDirection() == Player::Left)
        {
            if(player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
               || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds())
               || player->getSprite().getGlobalBounds().intersects(block->getSprite().getGlobalBounds()))
                    return true;
        }
}

bool CollisionManager::isCollision(Player *player, Reward* reward)
{
    if(player->getSprite().getGlobalBounds().intersects(reward->getSprite().getGlobalBounds()))
    {
        return true;
    }
    else
        return false;
}

bool CollisionManager::isCollision(Player *player, Bomb* bomb)
{
    if(player->getSprite().getGlobalBounds().intersects(bomb->getSprite().getGlobalBounds()))
    {
        return true;
    }
    else
        return false;
}
