#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <SFML/Graphics.hpp>
class button
{
    public:
        std::pair<int,int> leftUpperCornerPosition,rightLowerCornerPosition;
        bool isSelected=false;
        button(std::pair<int,int> leftUpper,std::pair<int,int> rightLower);
        ~button();
        sf::Text toText(std::string stringText, sf::Font fontType, int fontSize)
        {
            sf::Text txt(stringText,fontType,fontSize);
            txt.setPosition({this->leftUpperCornerPosition.first,this->leftUpperCornerPosition.second});
            if (this->isSelected)
                txt.setColor(sf::Color::Red);
            return txt;
        }
        void select()
        {
            this->isSelected=true;
        }
        void checkSelection(std::pair<int,int> mousePosition)
        {
            if (mousePosition.first>=leftUpperCornerPosition.first && mousePosition.first<=rightLowerCornerPosition.first
                && mousePosition.second>=leftUpperCornerPosition.second && mousePosition.second<=rightLowerCornerPosition.second)
            {
                isSelected=true;
                std::cout<<"DA"<<std::endl;
            }
            else
            {
                isSelected=false;
                std::cout<<"NO "<<mousePosition.first<<" "<<mousePosition.second<<std::endl;
            }
        }
        void setCoords(std::pair<int,int> lUCP,std::pair<int,int>rLCP)
        {
            leftUpperCornerPosition=lUCP;
            rightLowerCornerPosition=rLCP;
        }


    protected:

    private:
};

#endif // BUTTON_H
