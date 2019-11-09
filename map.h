#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "block.h"
#include "bomb.h"

#define MAPWIDTH 20
#define MAPHEIGHT 9

class Map : public sf::Drawable
{
public:
    Map();

    void load(std::string fileName);
    void setBlock(Block bloc, int i);

    Block *getBlock(int i) const;

    unsigned int getMapWidth() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    unsigned int blockSize;
    std::vector<int> map;
    std::vector<Block*> block;
    unsigned int mapHeight;
    unsigned int mapWidth;
    sf::Texture texture;

    std::vector<Bomb*> vecBomb;
};

#endif // MAP_H
