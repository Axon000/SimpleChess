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

bool queen::isMoveOk() const
{
    std::cout << "call in queen" << std::endl;
    return 1;
}
