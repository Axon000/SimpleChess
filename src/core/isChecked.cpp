#include <iostream>

#include "isChecked.h"
#include "king.h"
#include "game.h"
#include "cmove.h"

using namespace std;

bool isChecked(square kingSqr, game g){

    bool output=0;
    cmove mtest;
    mtest.setEndPos(kingSqr);

    for(int i=0; i<8 ; i++){
        for(int j=0; j<8; j++){
            if(g.getSquareAt(i,j).getHasPiece() && !(g.getSquareAt(i,j).getPosX() == kingSqr.getPosX() && g.getSquareAt(i,j).getPosY() == kingSqr.getPosY())){
                mtest.setStartPos(g.getSquareAt(i,j));
                mtest.setPiece(g.getSquareAt(i,j).getPiece());
                if(g.getSquareAt(i,j).getPiece()->isMoveOk(&g, &mtest)){
                    output = 1;
                }
            }
        }
    }



    return output;
}

