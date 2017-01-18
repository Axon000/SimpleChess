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

bool rook::isMoveOk(game* g, cmove* m) const
{
    return 0;
}
