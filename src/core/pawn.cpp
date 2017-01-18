#include <iostream>
#include "pawn.h"
#include "cmove.h"
#include "game.h"

using namespace std;

pawn::pawn()
{
    //ctor
    this->setLabel('p');

}

pawn::~pawn()
{
    //dtor
}

/* return true if the move given in argument is ok in the game provided. */
bool pawn::isMoveOk(game* g, cmove* m) const
{
    bool output = 0;

    /*if parent test is not ok, the move is not ok. piece::isMoveOk tests if there is a piece of good type at start point,
    if move suppress an existing check, and if the piece is of the good color */


    if(piece::isMoveOk(g, m)){
        int startX = m->getStartPos().getPosX();
        int startY = m->getStartPos().getPosY();
        int endX = m->getEndPos().getPosX();
        int endY = m->getEndPos().getPosY();


        bool simpleForward = (startX == endX && endY==startY + 1 && !g->getSquareAt(endX, endY).getHasPiece());
        bool doubleForward = (startX == endX && endY == 3 && startY == 1 && !g->getSquareAt(endX, endY).getHasPiece());
        bool eatForward = ((endX == startX + 1 || endX == startX-1) && endY== startY + 1) && g->getSquareAt(endX, endY).getHasPiece() && !g->getSquareAt(endX, endY).getPiece()->getIsWhite() ;


        bool simpleDownward = (startX == endX && endY==startY - 1 && !g->getSquareAt(endX, endY).getHasPiece());
        bool doubleDownward = (startX == endX && endY == 4 && startY == 6 && !g->getSquareAt(endX, endY).getHasPiece());
        bool eatDownward = ((endX == startX + 1 || endX == startX- 1) && endY== startY - 1) && g->getSquareAt(endX, endY).getHasPiece() && g->getSquareAt(endX, endY).getPiece()->getIsWhite() ;


        if(m->getPiece()->getIsWhite()){

            if(simpleForward || doubleForward || eatForward){
                output = 1;
            }

        }
        else{

            if(simpleDownward || doubleDownward || eatDownward){
                output = 1;
            }

        }

    }

    return output;

}
