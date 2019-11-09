#include "map.h"

Map::Map()
    :blockSize(40)
{

}

void Map::load(std::string fileName)
{
    std::ifstream file(fileName, std::ios::in);
    std::string tmp;

    if(!file)
        std::cout << "Fichier non trouve" << std::endl;

    while(std::getline(file, tmp))
    {
        for(unsigned int i=0; i < tmp.length(); i++)
        {
            mapWidth = tmp.length();
            map.push_back(tmp[i] - '0');
        }
    }
    mapHeight = map.size() / mapWidth;
    file.close();

    for(unsigned int i=0; i < map.size(); i++)
    {
        if(map[i] == 3)
        {
            block.push_back(new Block(1, sf::Vector2i((i%mapWidth)*blockSize, (i/mapWidth)*blockSize)));
        }
        else if(map[i] == 2)
        {
            block.push_back(new Block(0, sf::Vector2i((i%mapWidth)*blockSize, (i/mapWidth)*blockSize)));
        }
        else if(map[i] == 0)
        {
            block.push_back(new Block(2, sf::Vector2i((i%mapWidth)*blockSize, (i/mapWidth)*blockSize)));
        }
        else if(map[i] == 1)
        {
            block.push_back(new Block(3, sf::Vector2i((i%mapWidth)*blockSize, (i/mapWidth)*blockSize)));
        }
    }
    std::cout << "---------------------" << map.size() << "blocks" << std::endl;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(unsigned int i = 0; i < block.size(); i++)
    {
        target.draw(*block[i]);
    }
}

Block *Map::getBlock(int i) const
{
    return block[i];
}

unsigned int Map::getMapWidth() const
{
    return mapWidth;
}

void Map::setBlock(Block bloc, int i)
{
    block[i] = new Block(bloc);
}
