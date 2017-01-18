#include <iostream>
#include "queen.h"

queen::queen()
{
    //ctor
    this->setLabel('Q');
}

queen::~queen()
{
    //dtor
}

bool queen::isMoveOk(game* g, cmove* m) const
{
    return 0;
}
