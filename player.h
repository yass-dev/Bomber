#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "reward.h"

class Player : public sf::Drawable
{

public:
    Player();

    void update();
    void setPosition(sf::Vector2f pos);
    void setPosition(int x, int y);
    void setSpeed(int speeds);
    void setCanMove(bool can);
    void applyReward(Reward rew);

    sf::Vector2f getExPos() const;
    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;
    int getDirection() const;
    int getSize() const;
    int getFire() const;
    int getPoseBomb() const;
    int getSpeed() const;

    enum Dir{Down, Left, Right, Up};

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void gestionClavier();
    void gestionSprite();
    void gestionFPS();

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock Time;
    sf::Vector2i anim;

    bool updateFPS = true;
    bool canMove;
    const int playerSize;
    sf::Vector2f exPos;

    int speed = 10;
    int bomb = 1;
    int fire = 1;
};

#endif // PLAYER_H
