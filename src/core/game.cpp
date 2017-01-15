#include <iostream>
#include <vector>
#include "game.h"
#include "move.h"
#include "square.h"
#include "rook.h"
#include "piece.h"

using namespace std;



bool game::checkMove(piece const& p, move m){
    return p.isMoveOk();
}

void game::setStartPosition(){


//pawns
    for(int i = 0; i<8; i++){

        m_board[i][1].setHasPiece(1);
        m_board[i][1].setPiece(&this->m_pw[i]);
        m_board[i][6].setHasPiece(1);
        m_board[i][6].setPiece(&this->m_pb[i]);

        m_board[i][0].setHasPiece(1);
        m_board[i][7].setHasPiece(1);

    }


//rooks
    m_board[0][0].setPiece(&this->m_rw[0]);
    m_board[0][7].setPiece(&this->m_rb[0]);
    m_board[7][0].setPiece(&this->m_rw[1]);
    m_board[7][7].setPiece(&this->m_rb[1]);




//bishops
    m_board[2][0].setPiece(&this->m_bw[0]);
    m_board[2][7].setPiece(&this->m_bb[0]);
    m_board[5][0].setPiece(&this->m_bw[1]);
    m_board[5][7].setPiece(&this->m_bb[1]);

//knights
    m_board[1][0].setPiece(&this->m_nw[0]);
    m_board[1][7].setPiece(&this->m_nb[0]);
    m_board[6][0].setPiece(&this->m_nw[1]);
    m_board[6][7].setPiece(&this->m_nb[1]);

//queen/king
    m_board[3][0].setPiece(&this->m_qw);
    m_board[3][7].setPiece(&this->m_qb);
    m_board[4][0].setPiece(&this->m_kw);
    m_board[4][7].setPiece(&this->m_kb);


}

game::game()
{

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



void game::castMove(move nextMove)
{

    rook test;

    if(checkMove(*nextMove.getPiece(), nextMove)){
    //if(checkMove(test)){
        getMoveList().push_back(nextMove);
        m_board[nextMove.getStartPos().getPosX()][nextMove.getStartPos().getPosY()].setHasPiece(0);
        /*
        if this.m_board[nextMove.GetendPos().GetposX()][nextMove.GetendPos().GetposY()].GethasPiece(){

        }
        */

        m_board[nextMove.getEndPos().getPosX()][nextMove.getEndPos().getPosY()].setHasPiece(1);
        m_board[nextMove.getEndPos().getPosX()][nextMove.getEndPos().getPosY()].setPiece(nextMove.getPiece());
    }

}


std::vector<move> game::getMoveList() { return m_moveList; }
void game::setMoveList(std::vector<move> val) { m_moveList = val; }
square game::getSquareAt(int posX, int posY)
{

//std::cout << "game getter pos : " << posX << " " << posY << std::endl;
//std::cout << "game getter squareAt : " << m_board[posX][posY].getPosX() << " " << m_board[posX][posY].getPosY() << std::endl;
return m_board[posX][posY];

}

