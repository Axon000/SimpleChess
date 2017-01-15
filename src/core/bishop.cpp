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

bool bishop::isMoveOk() const
{
    std::cout << "call in bishop" << std::endl;
    return 1;
}
