#include <iostream>
#include "piece.h"
#include "cmove.h"
#include "game.h"

using namespace std;

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

    bool hasPiece = m->getStartPos().getHasPiece();
    bool goodTeam = (m->getStartPos().getPiece()->getIsWhite() && g->getWhiteToPlay()) || (!m->getStartPos().getPiece()->getIsWhite() && !g->getWhiteToPlay());



    if(hasPiece && goodTeam){

        return 1;

    }
    else{
        return 0;
    }
}


char piece::getLabel(){ return m_label; }
void piece::setLabel(char lab){ m_label = lab; }
bool piece::getIsWhite(){ return m_isWhite; }
void piece::setIsWhite(bool val){ m_isWhite= val; }
