#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED



#endif // MAINMENU_H_INCLUDED
#include <button.h>
#include <vector>
int mainmenu(sf::RenderWindow &window)
{
    std::vector<button> buttonList;
    button newButton({500,500},{600,550});
    buttonList.push_back(newButton);
    newButton.setCoords({500,600},{600,650});
    buttonList.push_back(newButton);

    sf::Font arial;
    if  (!arial.loadFromFile("fonts/arial.ttf"))
    {
        std::cout<<"Error loading arial.ttf"<<std::endl;
    }
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

        window.draw(buttonList[0].toText("Play",arial,30));
        window.draw(buttonList[1].toText("Exit",arial,30));
        window.display();
        window.clear();
    }
    exit(0);
}
