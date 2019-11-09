#include "bombmanager.h"

BombManager::BombManager(Player *pl)
    : canContinueRight(true), canContinueUp(true), canContinueDown(true), canContinueLeft(true), canConinueExplose(true)
{
    player = pl;
    texture.loadFromFile("explosion.png");
}

void BombManager::addBomb(sf::Vector2f pos)
{
    int i =(int)(pos.x / blockSize) + (int)(pos.y / blockSize)*mapWidth;
    int x = (i%mapWidth)*blockSize;
    int y = (i/mapWidth)*blockSize;

    vecBomb.push_back(new Bomb(sf::Vector2f(x, y)));
    std::cout << "Bomb placed at" << pos.x << " ; " << pos.y <<std::endl;
}

void BombManager::update(sf::Vector2f pos, unsigned int fire, unsigned int mapwidth, unsigned int blocksize, Map *maps)
{
    playerFire = 4*fire;
    mapWidth = mapwidth;
    blockSize = blocksize;
    map = maps;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(vecBomb.size() < player->getPoseBomb())
            addBomb(pos);
    }
    for(unsigned int i=0; i < vecBomb.size(); i++)
    {
        if(vecBomb[i]->isExplosed())
        {
            exploseBomb(i, false, Null);
            vecBomb.erase(vecBomb.begin() + i);
        }
    }
}

void BombManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(unsigned int i = 0; i < vecBomb.size(); i++)
    {
        target.draw(*vecBomb[i]);
    }
    for(unsigned int i = 0; i < vecReward.size(); i++)
    {
        target.draw(*vecReward[i]);
    }
    for(unsigned int i=0; i < vecExplosion.size(); i++)
    {
        target.draw(*vecExplosion[i]);
    }
}

void BombManager::exploseBomb(unsigned int pos, bool fromAnotherBomb, Dir direction)
{
    int i =(int)(vecBomb[pos]->getPosition().x / blockSize) + (int)(vecBomb[pos]->getPosition().y / blockSize)*mapWidth;
    int x = (i%mapWidth)*blockSize;
    int y = (i/mapWidth)*blockSize;

    std::cout << "X=" << x << " ; Y=" << y <<std::endl;

    int aboveBlock = i - mapWidth;
    int belowBlock = i + mapWidth;
    int rightBlock = i + 1;
    int leftBlock = i - 1;

    if(!fromAnotherBomb)
    {
        for(unsigned int i = 0; i < player->getFire(); i++)
        {
            if(canContinueUp)
            {
                if(map->getBlock(aboveBlock)->isBreakable())
                {
                    map->getBlock(aboveBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(aboveBlock)->getPosition());
                    map->getBlock(aboveBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(aboveBlock)->getReward()));
                    map->setBlock(*bloc, aboveBlock);
                    Explosion *explosion = new Explosion(map->getBlock(aboveBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(aboveBlock)->isBreakable() && map->getBlock(aboveBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(aboveBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueUp = false;
                            exploseBomb(j, true, Dir::Down);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(aboveBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueUp = false;
                }
            }
            if(canContinueRight)
            {
                if(map->getBlock(rightBlock)->isBreakable())
                {
                    map->getBlock(rightBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(rightBlock)->getPosition());
                    map->getBlock(rightBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(rightBlock)->getReward()));
                    map->setBlock(*bloc, rightBlock);
                    Explosion *explosion = new Explosion(map->getBlock(rightBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(rightBlock)->isBreakable() && map->getBlock(rightBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(rightBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueRight = false;
                            exploseBomb(j, true, Dir::Left);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(rightBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueRight = false;
                }
            }
            if(canContinueDown)
            {
                if(map->getBlock(belowBlock)->isBreakable())
                {
                    map->getBlock(belowBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(belowBlock)->getPosition());
                    map->getBlock(belowBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(belowBlock)->getReward()));
                    map->setBlock(*bloc, belowBlock);
                    Explosion *explosion = new Explosion(map->getBlock(belowBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(belowBlock)->isBreakable() && map->getBlock(belowBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(belowBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueDown = false;
                            exploseBomb(j, true, Dir::Up);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(belowBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueRight = false;
                }
            }
            if(canContinueLeft)
            {
                if(map->getBlock(leftBlock)->isBreakable())
                {
                    map->getBlock(leftBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(leftBlock)->getPosition());
                    map->getBlock(leftBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(leftBlock)->getReward()));
                    map->setBlock(*bloc, leftBlock);
                    Explosion *explosion = new Explosion(map->getBlock(leftBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(leftBlock)->isBreakable() && map->getBlock(leftBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(leftBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueLeft = false;
                            exploseBomb(j, true, Dir::Right);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(leftBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueRight = false;
                }
            }
            aboveBlock -= mapWidth;
            belowBlock += mapWidth;
            rightBlock += 1;
            leftBlock -= 1;
        }
    }
    else if(fromAnotherBomb)
    {
        for(unsigned int i = 0; i < player->getFire(); i++)
        {
            if(canContinueUp && direction != Dir::Up)
            {
                if(map->getBlock(aboveBlock)->isBreakable())
                {
                    map->getBlock(aboveBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(aboveBlock)->getPosition());
                    map->getBlock(aboveBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(aboveBlock)->getReward()));
                    map->setBlock(*bloc, aboveBlock);
                    Explosion *explosion = new Explosion(map->getBlock(aboveBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueUp = false;
                            exploseBomb(j, true, Dir::Down);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(!map->getBlock(aboveBlock)->isBreakable() && map->getBlock(aboveBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(aboveBlock)->getPosition());
                    vecExplosion.push_back(explosion);

                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueUp = false;
                            exploseBomb(j, true, Dir::Down);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(aboveBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueUp = false;
                }
            }
            if(canContinueRight && direction != Dir::Right)
            {
                if(map->getBlock(rightBlock)->isBreakable())
                {
                    map->getBlock(rightBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(rightBlock)->getPosition());
                    map->getBlock(rightBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(rightBlock)->getReward()));
                    map->setBlock(*bloc, rightBlock);
                    Explosion *explosion = new Explosion(map->getBlock(rightBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(rightBlock)->isBreakable() && map->getBlock(rightBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(rightBlock)->getPosition());
                    vecExplosion.push_back(explosion);

                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueRight = false;
                            exploseBomb(j, true, Dir::Left);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(rightBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueRight = false;
                }
            }
            if(canContinueDown && direction != Dir::Down)
            {
                if(map->getBlock(belowBlock)->isBreakable())
                {
                    map->getBlock(belowBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(belowBlock)->getPosition());
                    map->getBlock(belowBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(belowBlock)->getReward()));
                    map->setBlock(*bloc, belowBlock);
                    Explosion *explosion = new Explosion(map->getBlock(belowBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(belowBlock)->isBreakable() && map->getBlock(belowBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(belowBlock)->getPosition());
                    vecExplosion.push_back(explosion);

                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueDown = false;
                            exploseBomb(j, true, Dir::Up);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(belowBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueRight = false;
                }
            }
            if(canContinueLeft && direction != Dir::Left)
            {
                if(map->getBlock(leftBlock)->isBreakable())
                {
                    map->getBlock(leftBlock)->getReward()->generateId();
                    Block *bloc = new Block(Block::GRASS, map->getBlock(leftBlock)->getPosition());
                    map->getBlock(leftBlock)->destroy();
                    vecReward.push_back(new Reward(*map->getBlock(leftBlock)->getReward()));
                    map->setBlock(*bloc, leftBlock);
                    Explosion *explosion = new Explosion(map->getBlock(leftBlock)->getPosition());
                    vecExplosion.push_back(explosion);
                }
                else if(!map->getBlock(leftBlock)->isBreakable() && map->getBlock(leftBlock)->getType() != Block::INDESTRUCTIBLE)
                {
                    Explosion *explosion = new Explosion(map->getBlock(leftBlock)->getPosition());
                    vecExplosion.push_back(explosion);

                    for(unsigned int j=0; j < vecBomb.size(); j++)
                    {
                        if(explosion->getPosition() == vecBomb[j]->getPosition())
                        {
                            canContinueLeft = false;
                            exploseBomb(j, true, Dir::Right);
                            vecBomb.erase(vecBomb.begin() + j);
                        }
                    }
                }
                else if(map->getBlock(leftBlock)->getType() == Block::INDESTRUCTIBLE)
                {
                    canContinueRight = false;
                }
            }
            aboveBlock -= mapWidth;
            belowBlock += mapWidth;
            rightBlock += 1;
            leftBlock -= 1;
        }
    }

    canContinueUp = true;
    canContinueRight = true;
    canContinueDown = true;
    canContinueLeft = true;
    canConinueExplose = true;
}

std::vector<Bomb*> BombManager::getBombs() const
{
    return vecBomb;
}

std::vector<Reward*> BombManager::getRewards() const
{
    return vecReward;
}
