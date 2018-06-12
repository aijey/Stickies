#include <SFML/Graphics.hpp>
#include "button.h"
#include <iostream>
#include <string>
button::button(std::pair<int,int> leftUpper,std::pair<int,int> rightLower)
{
    std::cout<<"Button has been created"<<std::endl;
    this->leftUpperCornerPosition=leftUpper;
    this->rightLowerCornerPosition=rightLower;
}

button::~button()
{
    std::cout<<"Button has been destroyed"<<std::endl;
}
