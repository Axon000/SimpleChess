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
    std::cout << "call in bishop" << std::endl;
    return 1;
}
