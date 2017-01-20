#include <iostream>
#include <stdlib.h>
#include "king.h"
#include "cmove.h"
#include "game.h"

using namespace std;

king::king()
{
    //ctor
    this->setLabel('K');
}

king::~king()
{
    //dtor
}

bool king::isMoveOk(game* g, cmove* m) const
{
    if(piece::isMoveOk(g, m)){
        int startX = m->getStartPos().getPosX();
        int startY = m->getStartPos().getPosY();
        int endX = m->getEndPos().getPosX();
        int endY = m->getEndPos().getPosY();

        if(abs(startX-endX) <= 1 && abs(startY-endY) <=1){
            return 1;
        }
        else{
            return 0;
        }
    }
}
