#include <SFML/Graphics.hpp>
#include<iostream>
#include "game.h"
#include "mainmenu.h"
#include "gameover.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Stickies!");
    std::cout<<window.getPosition().x<<" "<<window.getPosition().y<<std::endl;
    window.setFramerateLimit(120);
    window.setPosition({window.getPosition().x,0});
    int mainmenucode=mainmenu(window);
    if (mainmenucode==1)
    {
        exitGame:
        exit(0);
    }
    if (mainmenucode==0)
    {
        startGame:
        int gamecode=game(window);
        int gameovercode=gameover(window,gamecode);
        if (gameovercode==0)
            goto startGame;
        if (gameovercode==1)
            goto exitGame;
    }
    return 0;
}
