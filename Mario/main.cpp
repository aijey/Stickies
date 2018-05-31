#include <SFML/Graphics.hpp>
#include<iostream>
int usedPosition[101][101];
void doMove(bool &W,bool &A, bool &S, bool &D, sf::CircleShape &shape, int playerNum, sf::RenderWindow &window)
{
    if (W) shape.move(0,-10);
    if (A) shape.move(-10,0);
    if (S) shape.move(0,10);
    if (D) shape.move(10,0);
    if (shape.getPosition().x<0) shape.setPosition(1000+shape.getPosition().x,shape.getPosition().y);
    if (shape.getPosition().y<0) shape.setPosition(shape.getPosition().x,shape.getPosition().y+1000);
    shape.setPosition((int)shape.getPosition().x%1000,(int)shape.getPosition().y%1000);
    int x=shape.getPosition().x/10;
    int y=shape.getPosition().y/10;
    //std::cout<<x<<" "<<y<<std::endl;
    std::cout<<playerNum<<std::endl;
    if (usedPosition[x][y])
    {
        std::cout<<"Player "<<playerNum<<" lost."<<std::endl;
        window.close();
        sf::Clock Clock;
        while (Clock.getElapsedTime().asSeconds()<1)
        {

        }
        Clock.restart();
        exit(0);

    }
    else
        usedPosition[x][y]=playerNum;
    //std::cout<<shape.getPosition().x<<" "<<shape.getPosition().y<<std::endl;
    return;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setFramerateLimit(120);
    sf::CircleShape player1(5.f);
    sf::CircleShape player2(5.f);
    player1.setPosition(0,0);
    player2.setPosition(990,990);
    player1.setFillColor(sf::Color::White);
    player2.setFillColor(sf::Color::Red);
    bool W=0,A=0,S=0,D=1,Up=1,Left=0,Down=0,Right=0;
    bool player1CoolDown=0,player2CoolDown=0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W && !S && !player1CoolDown)
                    W=1,A=0, S=0, D=0, player1CoolDown=1;
                else
                if (event.key.code == sf::Keyboard::A && !D && !player1CoolDown)
                    A=1, W=0,S=0,D=0, player1CoolDown=1;
                else
                if (event.key.code == sf::Keyboard::S && !W && !player1CoolDown)
                    S=1,W=0,A=0,D=0, player1CoolDown=1;
                else
                if (event.key.code == sf::Keyboard::D && !A && !player1CoolDown)
                    D=1,W=0,A=0,S=0, player1CoolDown=1;

                if (event.key.code == sf::Keyboard::Up && !Down && !player2CoolDown)
                    Up=1, Left=0, Down=0, Right=0,player2CoolDown=1;
                else
                if (event.key.code == sf::Keyboard::Left && !Right && !player2CoolDown)
                    Left=1, Up=0, Down=0, Right=0, player2CoolDown=1;
                else
                if (event.key.code == sf::Keyboard::Down && !Up && !player2CoolDown)
                    Down=1, Up=0, Left=0, Right=0, player2CoolDown=1;
                else
                if (event.key.code == sf::Keyboard::Right && !Left && !player2CoolDown)
                    Right=1, Up=0,Left=0,Down=0, player2CoolDown=1;

                if (event.key.code== sf::Keyboard::R)
                    window.clear();

            }

        }
        doMove(W,A,S,D,player1,1,window);
        doMove(Up,Left,Down,Right,player2,2,window);
        player1CoolDown=0;
        player2CoolDown=0;
        sf::Clock Clock;
        while (Clock.getElapsedTime().asSeconds()<0.05)
        {

        }
        Clock.restart();


        window.clear();
        std::pair<int,int> player1Position={player1.getPosition().x,player1.getPosition().y};
        std::pair<int,int> player2Position={player2.getPosition().x,player2.getPosition().y};
        for (int i=0; i<=100; i++)
        {
            for (int j=0; j<=100; j++)
            {
                int x=i*10;
                int y=j*10;
                if (usedPosition[i][j]==1) {
                    player1.setPosition(x,y);
                    window.draw(player1);
                }
                if (usedPosition[i][j]==2) {
                    player2.setPosition(x,y);
                    window.draw(player2);
                }
            }
        }

        player1.setPosition(player1Position.first,player1Position.second);
        player2.setPosition(player2Position.first,player2Position.second);
        window.display();
    }

    return 0;
}

