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
    std::cout << "call in knight" << std::endl;
    return 1;
}
