#include <iostream>
#include "rook.h"

rook::rook()
{
    //ctor
    this->setLabel('R');
}

rook::~rook()
{
    //dtor
}

bool rook::isMoveOk() const
{
    std::cout << "call in rook" << std::endl;
    return 1;
}
