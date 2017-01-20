#include <iostream>
#include <stdlib.h>
#include "misc.h"
#include "bishop.h"
#include "cmove.h"
#include "game.h"

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
    bool output = 0;

    /*if parent test is not ok, the move is not ok. piece::isMoveOk tests if there is a piece of good type at start point,
    if move suppress an existing check, and if the piece is of the good color */


    if(piece::isMoveOk(g, m)){
        int startX = m->getStartPos().getPosX();
        int startY = m->getStartPos().getPosY();
        int endX = m->getEndPos().getPosX();
        int endY = m->getEndPos().getPosY();


        bool moveindiag = (abs(startX-endX) == abs(startY-endY));
        bool noobstacle = 0;



        if(moveindiag){
            output=1;
            for(int i= 1; i< abs(endY-startY); i++){
                if(g->getSquareAt(startX+i*sign(endX-startX), startY+i*sign(endY-startY)).getHasPiece()){
                    output=0;
                }
            }
        }



    }

    return output;
}
