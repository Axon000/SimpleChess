#include <iostream>
#include "knight.h"

knight::knight()
{
    //ctor
    this->setLabel('N');
}

knight::~knight()
{
    //dtor
}

bool knight::isMoveOk(game* g, cmove* m) const
{
    return 0;
}
