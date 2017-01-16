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


        m_pw.push_back(new pawn());
        m_board[i][1].setHasPiece(1);
        m_board[i][1].setPiece(m_pw[i]);
        m_pb.push_back(new pawn());
        m_board[i][6].setHasPiece(1);
        m_board[i][6].setPiece(m_pb[i]);


        //addPiece(m_pw, new piece(pawn()), i, 1);
        //addPiece(m_pb, new piece(pawn()), i, 6);

        m_board[i][0].setHasPiece(1);
        m_board[i][7].setHasPiece(1);

    }


//rooks

    m_rw.push_back(new rook());
    m_rb.push_back(new rook());
    m_rw.push_back(new rook());
    m_rb.push_back(new rook());
    m_board[0][0].setPiece(m_rw[0]);
    m_board[0][7].setPiece(m_rb[0]);
    m_board[7][0].setPiece(m_rw[1]);
    m_board[7][7].setPiece(m_rb[1]);

//bishops

    m_bw.push_back(new bishop());
    m_bb.push_back(new bishop());
    m_bw.push_back(new bishop());
    m_bb.push_back(new bishop());
    m_board[2][0].setPiece(m_bw[0]);
    m_board[2][7].setPiece(m_bb[0]);
    m_board[5][0].setPiece(m_bw[1]);
    m_board[5][7].setPiece(m_bb[1]);


//knights

    m_nw.push_back(new knight());
    m_nb.push_back(new knight());
    m_nw.push_back(new knight());
    m_nb.push_back(new knight());
    m_board[1][0].setPiece(m_nw[0]);
    m_board[1][7].setPiece(m_nb[0]);
    m_board[6][0].setPiece(m_nw[1]);
    m_board[6][7].setPiece(m_nb[1]);


//queen/king

    m_qw.push_back(new queen());
    m_qb.push_back(new queen());
    m_kw.push_back(new king());
    m_kb.push_back(new king());
    m_board[3][0].setPiece(m_qw[0]);
    m_board[3][7].setPiece(m_qb[0]);
    m_board[4][0].setPiece(m_kw[0]);
    m_board[4][7].setPiece(m_kb[0]);




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

