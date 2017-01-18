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
    return 0;
}
