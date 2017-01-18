#include <iostream>
#include "bishop.h"

bishop::bishop()
{
    //ctor
    this->setLabel('B');
}

bishop::~bishop()
{
    //dtor
}

bool bishop::isMoveOk(game* g, cmove* m) const
{
    return 0;
}
