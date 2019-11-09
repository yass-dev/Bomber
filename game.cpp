#include "game.h"

Game::Game()
    :window(sf::VideoMode(800, 600), "Jeu"), view(player.getPosition(), sf::Vector2f(850.f, 750.f)), bombManager(&player)
{
    window.setFramerateLimit(10);
    map.load("map.txt");
    player.setPosition(40*5, 40*5);
}

void Game::run()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        bombManager.update(sf::Vector2f(player.getPosition().x + player.getSize()/2, player.getPosition().y+player.getSize()/2), player.getFire(), map.getMapWidth(), map.getBlock(0)->getBlockSize(), &map);

        player.update();
        view.setCenter(player.getPosition());
        checkCollision();

        window.draw(map);
        window.draw(bombManager);
        window.draw(player);

        window.display();
        window.clear(sf::Color::Black);
    }
}

void Game::checkCollision()
{
    highCurrentBlock = (int)((player.getPosition().x + player.getSize()/2) / map.getBlock(0)->getBlockSize()) + (int)((player.getPosition().y) / map.getBlock(0)->getBlockSize())*map.getMapWidth();
    currentBlock = (int)((player.getPosition().x + player.getSize()/2) / map.getBlock(0)->getBlockSize()) + (int)((player.getPosition().y + player.getSize()/2) / map.getBlock(0)->getBlockSize())*map.getMapWidth();
    lowCurrentBlock = (int)((player.getPosition().x + player.getSize()/2) / map.getBlock(0)->getBlockSize()) + (int)((player.getPosition().y + player.getSize()) / map.getBlock(0)->getBlockSize())*map.getMapWidth();

    highAboveBlock = highCurrentBlock - map.getMapWidth();
    aboveBlock = currentBlock - map.getMapWidth();
    lowAboveBlock = lowCurrentBlock - map.getMapWidth();

    highBelowBlock = highCurrentBlock + map.getMapWidth();
    belowBlock = currentBlock + map.getMapWidth();
    lowBelowBlock = lowCurrentBlock + map.getMapWidth();

    highRightBlock = highCurrentBlock + 1;
    rightBlock = currentBlock + 1;
    lowRightBlock = lowCurrentBlock + 1;

    highLeftBlock = highCurrentBlock - 1;
    leftBlock = currentBlock - 1;
    lowLeftBlock = lowCurrentBlock -1;

    std::cout << "At " << currentBlock<< std::endl;

    if(player.getDirection() == Player::Dir::Up && aboveBlock >= 0)
    {
        if((collisionManager.isCollision(&player, map.getBlock(aboveBlock)) && map.getBlock(aboveBlock)->isBlocker() && map.getBlock(aboveBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(highAboveBlock)) && map.getBlock(highAboveBlock)->isBlocker() && map.getBlock(highAboveBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(lowAboveBlock)) && map.getBlock(lowAboveBlock)->isBlocker() && map.getBlock(lowAboveBlock)->isActive()))
        {
            player.setPosition(player.getExPos());
        }
    }
    if(player.getDirection() == Player::Dir::Down)
    {
        if((collisionManager.isCollision(&player, map.getBlock(belowBlock)) && map.getBlock(belowBlock)->isBlocker() && map.getBlock(belowBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(highBelowBlock)) && map.getBlock(highBelowBlock)->isBlocker() && map.getBlock(highBelowBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(lowBelowBlock)) && map.getBlock(lowBelowBlock)->isBlocker() && map.getBlock(lowBelowBlock)->isActive()))
        {
            player.setPosition(player.getExPos());
        }
    }
    if(player.getDirection() == Player::Dir::Right)
    {
        if((collisionManager.isCollision(&player, map.getBlock(rightBlock)) && map.getBlock(rightBlock)->isBlocker() && map.getBlock(rightBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(highRightBlock)) && map.getBlock(highRightBlock)->isBlocker() && map.getBlock(highRightBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(lowRightBlock)) && map.getBlock(lowRightBlock)->isBlocker() && map.getBlock(lowRightBlock)->isActive()))
        {
            player.setPosition(player.getExPos());
        }
    }
    if(player.getDirection() == Player::Dir::Left && leftBlock >= 0)
    {
        if((collisionManager.isCollision(&player, map.getBlock(leftBlock)) && map.getBlock(leftBlock)->isBlocker() && map.getBlock(leftBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(highLeftBlock)) && map.getBlock(highLeftBlock)->isBlocker() && map.getBlock(highLeftBlock)->isActive())
           || (collisionManager.isCollision(&player, map.getBlock(lowLeftBlock)) && map.getBlock(lowLeftBlock)->isBlocker() && map.getBlock(lowLeftBlock)->isActive()))
        {
            player.setPosition(player.getExPos());
        }
    }

    for(unsigned int i = 0; i < bombManager.getRewards().size(); i++)
    {
        if(collisionManager.isCollision(&player, bombManager.getRewards()[i]))
        {
            player.applyReward(*bombManager.getRewards()[i]);
            bombManager.getRewards()[i]->destroy();
        }
    }
    if(bombManager.getBombs().size() > 10)
    {
        for(unsigned int i = 0; i < bombManager.getBombs().size(); i++)
        {
            if(collisionManager.isCollision(&player, bombManager.getBombs()[i]))
            {
                player.applyReward(*bombManager.getRewards()[i]);
                bombManager.getRewards()[i]->destroy();
            }
        }
    }
}
