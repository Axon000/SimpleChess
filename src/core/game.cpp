#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "game.h"
#include "cmove.h"
#include "square.h"
#include "rook.h"
#include "piece.h"
#include "isChecked.h"

using namespace std;



bool game::checkMove(piece const& p, cmove m){

    bool output = p.isMoveOk(this, &m);
    cout << "bef check check " << output << endl;


    /* Have to check if king is checked after move here, and not in piece.cpp, because isChecked() perform a test on other team all possible nextMove
    by using piece.cpp isMoveOk() method. If white is checked on this move (so that this move is not really possible according to the rules (you can't uncover
    your king)) by a piece that would uncover it's own king to eat white king, it is still a check, but the programm would have consider it an invalid eat, and
    would have said that white king is not checked, and the move ok. Puting the test here solve this problem.
    */
    if(!m_noking){
        game cpy = *this;
        cpy.addMove(m);
        square kingSqr = cpy.getPlayerKingSquare() ;
        cpy.setWhiteToPlay(!cpy.getWhiteToPlay());
        cout << kingSqr.getPosX() << " " << kingSqr.getPosY() << endl;
        if(output && isChecked(kingSqr, cpy)){
            output = 0;
        }
        cout << "aft check check " << output << endl;
    }
    cout << "aft check check " << output << endl;
    return output;

}

square game::getPlayerKingSquare() {
    for(int i=0; i<8 ; i++){
        for(int j=0; j<8; j++){
            if(m_whitetoplay && this->getSquareAt(i,j).getHasPiece() && this->getSquareAt(i,j).getPiece() == m_kw){
                return this->getSquareAt(i,j);
            }
            else if(!m_whitetoplay && this->getSquareAt(i,j).getHasPiece() && this->getSquareAt(i,j).getPiece() == m_kb){
                return this->getSquareAt(i,j);
            }
        }
    }
}

void game::addMove(cmove m){

        getMoveList().push_back(m);
        m_board[m.getStartPos().getPosX()][m.getStartPos().getPosY()].setHasPiece(0);

        m_board[m.getEndPos().getPosX()][m.getEndPos().getPosY()].setHasPiece(1);
        m_board[m.getEndPos().getPosX()][m.getEndPos().getPosY()].setPiece(m.getPiece());



        m_whitetoplay = !m_whitetoplay;
        //m_kingChecked = isChecked(this->getPlayerKingSquare(), *this);

}


void game::setStartPosition(){

    ifstream inputfile("data/default.txt", ios::in);
    if(!inputfile.is_open()){
        cerr << "Erreur à l'ouverture du fichier" << endl;
    }

    string line;
    char abc[]="abcdefgh";
    char s123[]="12345678";



    while(getline(inputfile, line)){
        if(line.at(1) == 'p'){
            if(line.at(0) == 'w'){
                m_pw.push_back(new pawn());
                m_pw.back()->setIsWhite(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_pw.back());
            }
            else if(line.at(0) == 'b'){
                m_pb.push_back(new pawn());
                m_pb.back()->setIsWhite(0);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_pb.back());
            }
        }
        else if(line.at(1) == 'r'){
            if(line.at(0) == 'w'){
                m_rw.push_back(new rook());
                m_rw.back()->setIsWhite(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_rw.back());
            }
            else if(line.at(0) == 'b'){
                m_rb.push_back(new rook());
                m_rb.back()->setIsWhite(0);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_rb.back());
            }
        }
        else if(line.at(1) == 'n'){
            if(line.at(0) == 'w'){
                m_nw.push_back(new knight());
                m_nw.back()->setIsWhite(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_nw.back());
            }
            else if(line.at(0) == 'b'){
                m_nb.push_back(new knight());
                m_nb.back()->setIsWhite(0);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_nb.back());
            }
        }
        else if(line.at(1) == 'b'){
            if(line.at(0) == 'w'){
                m_bw.push_back(new bishop());
                m_bw.back()->setIsWhite(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_bw.back());
            }
            else if(line.at(0) == 'b'){
                m_bb.push_back(new bishop());
                m_bb.back()->setIsWhite(0);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_bb.back());
            }
        }
        else if(line.at(1) == 'q'){
            if(line.at(0) == 'w'){
                m_qw.push_back(new queen());
                m_qw.back()->setIsWhite(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_qw.back());
            }
            else if(line.at(0) == 'b'){
                m_qb.push_back(new queen());
                m_qb.back()->setIsWhite(0);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_qb.back());
            }
        }
        else if(line.at(1) == 'k'){
            m_noking=0;
            if(line.at(0) == 'w'){
                m_kw = new king();
                m_kw->setIsWhite(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_kw);
            }
            else if(line.at(0) == 'b'){
                m_kb = new king();
                m_kb->setIsWhite(0);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setHasPiece(1);
                m_board[strchr(abc, line.at(2))-abc][strchr(s123, line.at(3))-s123].setPiece(m_kb);
            }
        }
    }
}

game::game()
{
    m_freemode=0;
    m_nocolorcheckmode=0;
    m_noking=1;
    m_whitetoplay = 1;

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

    if(m_freemode || checkMove(*nextmove.getPiece(), nextmove)){

        this->addMove(nextmove);

    }

}


std::vector<cmove> game::getMoveList() { return m_moveList; }
void game::setMoveList(std::vector<cmove> val) { m_moveList = val; }
square game::getSquareAt(int posX, int posY){ return m_board[posX][posY]; }
bool game::getWhiteToPlay() { return m_whitetoplay; }
void game::setWhiteToPlay(bool val){ m_whitetoplay = val; }
bool game::getNoColorCheckMode(){ return m_nocolorcheckmode; }





