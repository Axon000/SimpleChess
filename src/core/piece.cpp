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
    bool goodTeam = g->getNoColorCheckMode() || (m->getStartPos().getPiece()->getIsWhite() == g->getWhiteToPlay());
    bool noTeammate = !m->getEndPos().getHasPiece() || (m->getEndPos().getPiece()->getIsWhite() != m->getPiece()->getIsWhite());


    cout << "goodTeam " << goodTeam << endl;
    cout << "team white " << g->getWhiteToPlay() << endl;

    if(hasPiece && goodTeam && noTeammate){

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
