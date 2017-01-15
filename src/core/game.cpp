#include <iostream>
#include "game.h"
#include "pawn.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "knight.h"
#include "square.h"



bool game::checkMove(piece const& p){
    return p.isMoveOk();
}

void game::setStartPosition(){


    pawn pw[8];
    pawn pb[8];
    rook rw[2];
    rook rb[2];
    bishop bw[2];
    bishop bb[2];
    knight nw[2];
    knight nb[2];
    king kw;
    king kb;
    queen qw;
    queen qb;


//pawns
    for(int i = 0; i<8; i++){

        m_board[i][1].setHasPiece(1);
        m_board[i][1].setPiece(pw[i]);
        m_board[i][6].setHasPiece(1);
        m_board[i][6].setPiece(pb[i]);

        m_board[i][0].setHasPiece(1);
        m_board[i][7].setHasPiece(1);

    }

//rooks
    m_board[0][0].setPiece(rw[0]);
    m_board[0][7].setPiece(rb[0]);
    m_board[7][0].setPiece(rw[1]);
    m_board[7][7].setPiece(rb[1]);

//bishops
    m_board[2][0].setPiece(bw[0]);
    m_board[2][7].setPiece(bb[0]);
    m_board[5][0].setPiece(bw[1]);
    m_board[5][7].setPiece(bb[1]);

//knights
    m_board[1][0].setPiece(nw[0]);
    m_board[1][7].setPiece(nb[0]);
    m_board[6][0].setPiece(nw[1]);
    m_board[6][7].setPiece(nb[1]);

//queen/king
    m_board[3][0].setPiece(qw);
    m_board[3][7].setPiece(qb);
    m_board[4][0].setPiece(kw);
    m_board[4][7].setPiece(kb);

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

    if(checkMove(nextMove.getPiece())){
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

