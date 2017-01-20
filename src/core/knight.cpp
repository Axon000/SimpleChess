#include <iostream>
#include <stdlib.h>
#include "knight.h"
#include "cmove.h"
#include "game.h"

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
    bool output = 0;

    /*if parent test is not ok, the move is not ok. piece::isMoveOk tests if there is a piece of good type at start point,
    if move suppress an existing check, and if the piece is of the good color */


    if(piece::isMoveOk(g, m)){
        int startX = m->getStartPos().getPosX();
        int startY = m->getStartPos().getPosY();
        int endX = m->getEndPos().getPosX();
        int endY = m->getEndPos().getPosY();

        bool verticalmove = (abs(endX-startX) == 2 && abs(endY-startY) == 1);
        bool horizontalmove = (abs(endX-startX) == 1 && abs(endY-startY) == 2);

        if(verticalmove || horizontalmove){
            output=1;
        }



    }

    return output;
}

