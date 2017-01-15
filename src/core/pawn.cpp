#include <iostream>
#include "pawn.h"

pawn::pawn()
{
    //ctor
    this->setLabel('p');

}

pawn::~pawn()
{
    //dtor
}

bool pawn::isMoveOk() const
{
    std::cout << "call in pawn" << std::endl;
    return 1;
}
