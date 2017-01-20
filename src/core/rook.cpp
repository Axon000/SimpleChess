#include <iostream>
#include <stdlib.h>
#include "misc.h"
#include "rook.h"
#include "cmove.h"
#include "game.h"


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
    bool output = 0;

    /*if parent test is not ok, the move is not ok. piece::isMoveOk tests if there is a piece of good type at start point,
    if move suppress an existing check, and if the piece is of the good color */


    if(piece::isMoveOk(g, m)){
        int startX = m->getStartPos().getPosX();
        int startY = m->getStartPos().getPosY();
        int endX = m->getEndPos().getPosX();
        int endY = m->getEndPos().getPosY();

        bool horizontalmove = (startY == endY);
        bool verticalmove = (endX == startX);
        bool moveinline = horizontalmove || verticalmove;
        bool noobstacle = 0;

        std::cout << horizontalmove << verticalmove << std::endl;

        if(moveinline){
            if(verticalmove){
                output=1;
                for(int i= 1; i< abs(endY-startY); i++){
                    if(g->getSquareAt(startX, startY+i*sign(endY-startY)).getHasPiece()){
                        output=0;
                    }
                }
            }
            else if(horizontalmove){
                output=1;
                std::cout << "entered rook deep condition" << std::endl;
                for(int i= 1; i< abs(endX - startX); i++){
                    if(g->getSquareAt(startX+i*sign(endX-startX), startY).getHasPiece()){
                        std::cout << startX+i*sign(endX-startX) << startY << std::endl;
                        output=0;
                    }
                }
            }
        }



    }

    return output;
}
