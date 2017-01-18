#include <iostream>
#include "piece.h"
#include "cmove.h"
#include "game.h"
#include "isChecked.h"


piece::piece()
{
    //ctor
}

piece::~piece()
{
    //dtor
    //std::cout << "call to destructor" << std::endl;
}

bool piece::isMoveOk(game* g, cmove* m) const {

    std::cout << "call in piece" << std::endl;

    bool output = 0;

    bool hasPiece = m->getStartPos().getHasPiece();
    bool goodTeam = (m->getStartPos().getPiece()->getIsWhite() && g->getWhiteToPlay()) || (!m->getStartPos().getPiece()->getIsWhite() && !g->getWhiteToPlay());


    if(hasPiece && goodTeam){

        game cpy = *g;
        cpy.addMove(*m);
        king king = g->getPlayerKing() ;
        if(!isChecked(king,cpy)){
            output = 1;
        }

    }

    return 1;
}


char piece::getLabel(){ return m_label; }
void piece::setLabel(char lab){ m_label = lab; }
bool piece::getIsWhite(){ return m_isWhite; }
void piece::setIsWhite(bool val){ m_isWhite= val; }
