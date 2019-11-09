#include "player.h"

Player::Player()
    : anim(1, Down), playerSize(32), speed(4), canMove(true), bomb(5)
{
    texture.loadFromFile("sprite.png");
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(anim.x * playerSize, anim.y * playerSize, playerSize, playerSize));
}

void Player::update()
{
    gestionClavier();
    gestionSprite();
    gestionFPS();
}

void Player::gestionClavier()
{
    if(canMove)
    {
        exPos = sprite.getPosition();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            updateFPS = true;
            anim.y = Up;
            sprite.move(0, -speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            updateFPS = true;
            anim.y = Down;
            sprite.move(0, speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            updateFPS = true;
            anim.y = Right;
            sprite.move(speed, 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            updateFPS = true;
            anim.y = Left;
            sprite.move(-speed, 0);
        }
        else
        {
            updateFPS = false;
        }
    }
}

void Player::gestionSprite()
{
    sprite.setTextureRect(sf::IntRect(anim.x * playerSize, anim.y * playerSize, playerSize, playerSize));
}

void Player::gestionFPS()
{
    if(updateFPS)
    {
        if(Time.getElapsedTime().asMilliseconds() >= 50)
        {
            anim.x--;
            if(anim.x * playerSize >= texture.getSize().x)
            {
                anim.x = 2;
            }
            Time.restart();
        }
    }
}

void Player::setSpeed(int speeds)
{
    speed = speeds;
}

void Player::setCanMove(bool can)
{
    canMove = can;
}

sf::Vector2f Player::getExPos() const
{
    return exPos;
}

int Player::getDirection() const
{
    return anim.y;
}

int Player::getSize() const
{
    return playerSize;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}

void Player::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

void Player::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}

sf::Sprite Player::getSprite() const
{
    return sprite;
}

int Player::getFire() const
{
    return fire;
}

void Player::applyReward(Reward rew)
{
    int id = rew.getId();
    switch(id)
    {
        case 0:
        fire++;
        std::cout << "Fire"<<std::endl;
        break;
        case 1:
        speed++;
        std::cout << "Speed" << std::endl;
        break;
        case 2:
        bomb++;
        std::cout << "Bomb" << std::endl;
        break;
    }
}

int Player::getPoseBomb() const
{
    return bomb;
}

int Player::getSpeed() const
{
    return speed;
}
