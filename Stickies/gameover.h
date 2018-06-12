#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED



#endif // GAMEOVER_H_INCLUDED
std::string to_string(int n)
{
    std::string res="";
    if (n<0)
    {
        res+="-";
        n=-n;
    }
    if (n==0)
        res+="0";
    std::string tmp;
    while(n!=0)
    {
        tmp=(char)((n%10)+'0')+tmp;
        n/=10;
    }
    res+=tmp;
    return res;
}
int gameover(sf::RenderWindow &window, int playerNum)
{

    std::vector<button> buttonList;
    button newButton({250,500},{350,550});
    buttonList.push_back(newButton);
    newButton.setCoords({750,500},{850,550});
    buttonList.push_back(newButton);
    sf::Font arial;

    if  (!arial.loadFromFile("fonts/arial.ttf"))
    {
        std::cout<<"Error loading arial.ttf"<<std::endl;
    }
    std::cout<<"Success"<<std::endl;
    sf::Text txt("Player "+to_string(playerNum)+" lost the game.",arial,50);
    txt.setPosition({280,300});
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)
            {
                window.close();
                exit(0);
            }
            std::pair<int,int> mousePosition={sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y};
            for (auto &i:buttonList)
            {
                i.checkSelection(mousePosition);
            }
            if (event.type==sf::Event::MouseButtonPressed)
            {
                for (int i=0; i<buttonList.size(); i++)
                {
                    if (buttonList[i].isSelected)
                        return i;
                }
            }
        }
        window.draw(txt);
        window.draw(buttonList[0].toText("Restart",arial,30));
        window.draw(buttonList[1].toText("Exit",arial,30));
        window.display();
        window.clear();

    }
    return 0;
}
