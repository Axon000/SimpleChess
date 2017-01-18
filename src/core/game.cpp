#include <iostream>
#include <vector>
#include "game.h"
#include "cmove.h"
#include "square.h"
#include "rook.h"
#include "piece.h"

using namespace std;



bool game::checkMove(piece const& p, cmove m){

    return p.isMoveOk(this, &m);

}

void game::addMove(cmove m){

        getMoveList().push_back(m);
        m_board[m.getStartPos().getPosX()][m.getStartPos().getPosY()].setHasPiece(0);

        m_board[m.getEndPos().getPosX()][m.getEndPos().getPosY()].setHasPiece(1);
        m_board[m.getEndPos().getPosX()][m.getEndPos().getPosY()].setPiece(m.getPiece());


        //m_kingChecked = isChecked(m_whitetoplay);
        //m_whitetoplay = !m_whitetoplay;

}


void game::setStartPosition(){


//pawns



    for(int i = 0; i<8; i++){


        m_pw.push_back(new pawn());
        m_pw[i]->setIsWhite(1);
        m_board[i][1].setHasPiece(1);
        m_board[i][1].setPiece(m_pw[i]);
        m_pb.push_back(new pawn());
        m_pb[i]->setIsWhite(0);
        m_board[i][6].setHasPiece(1);
        m_board[i][6].setPiece(m_pb[i]);


        m_board[i][0].setHasPiece(1);
        m_board[i][7].setHasPiece(1);

    }


//rooks

    m_rw.push_back(new rook());
    m_rw[0]->setIsWhite(1);
    m_rb.push_back(new rook());
    m_rb[0]->setIsWhite(0);
    m_rw.push_back(new rook());
    m_rw[1]->setIsWhite(1);
    m_rb.push_back(new rook());
    m_rb[1]->setIsWhite(0);
    m_board[0][0].setPiece(m_rw[0]);
    m_board[0][7].setPiece(m_rb[0]);
    m_board[7][0].setPiece(m_rw[1]);
    m_board[7][7].setPiece(m_rb[1]);

//bishops

    m_bw.push_back(new bishop());
    m_bw[0]->setIsWhite(1);
    m_bb.push_back(new bishop());
    m_bb[0]->setIsWhite(0);
    m_bw.push_back(new bishop());
    m_bw[1]->setIsWhite(1);
    m_bb.push_back(new bishop());
    m_bb[1]->setIsWhite(0);
    m_board[2][0].setPiece(m_bw[0]);
    m_board[2][7].setPiece(m_bb[0]);
    m_board[5][0].setPiece(m_bw[1]);
    m_board[5][7].setPiece(m_bb[1]);


//knights

    m_nw.push_back(new knight());
    m_nw[0]->setIsWhite(1);
    m_nb.push_back(new knight());
    m_nb[0]->setIsWhite(0);
    m_nw.push_back(new knight());
    m_nw[1]->setIsWhite(1);
    m_nb.push_back(new knight());
    m_nb[1]->setIsWhite(0);
    m_board[1][0].setPiece(m_nw[0]);
    m_board[1][7].setPiece(m_nb[0]);
    m_board[6][0].setPiece(m_nw[1]);
    m_board[6][7].setPiece(m_nb[1]);


//queen/king

    m_qw.push_back(new queen());
    m_qw[0]->setIsWhite(1);
    m_qb.push_back(new queen());
    m_qb[0]->setIsWhite(0);

    m_kw->setIsWhite(1);
    m_kb->setIsWhite(0);
    m_board[3][0].setPiece(m_qw[0]);
    m_board[3][7].setPiece(m_qb[0]);
    m_board[4][0].setPiece(m_kw);
    m_board[4][7].setPiece(m_kb);




}

game::game()
{
    m_kw = new king();
    m_kb = new king();

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            m_board[i][j].setPosX(i);
            m_board[i][j].setPosY(j);
            //std::cout << "m_board set pos :" << i << " " << j << " : " << m_board[i][j].getPosX() << " " << m_board[i][j].getPosY() << std::endl;

        }
    }
    setStartPosition();
}

game::~game()
{
    //dtor
}



void game::castMove(cmove nextmove)
{

    if(checkMove(*nextmove.getPiece(), nextmove)){

        this->addMove(nextmove);

    }

}


std::vector<cmove> game::getMoveList() { return m_moveList; }
void game::setMoveList(std::vector<cmove> val) { m_moveList = val; }
square game::getSquareAt(int posX, int posY){ return m_board[posX][posY]; }
bool game::getWhiteToPlay() { return m_whitetoplay; }
king game::getPlayerKing() {
    if(m_whitetoplay){
        return *m_kw;
    }
    else{
        return *m_kb;
    }
}



