#include <iostream>
#include "king.h"

king::king()
{
    //ctor
    this->setLabel('K');
}

king::~king()
{
    //dtor
}

bool king::isMoveOk() const
{
    std::cout << "call in king" << std::endl;
    return 1;
}
