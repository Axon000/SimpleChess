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

bool king::isMoveOk(game* g, cmove* m) const
{
    std::cout << "call in king" << std::endl;
    return 1;
}
