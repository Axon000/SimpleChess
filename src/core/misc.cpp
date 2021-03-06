#include <iostream>
#include <string>
#include <cstring>
#include "game.h"
#include "square.h"

using namespace std;

void printBoard(game game1){

    square sqr;

    for(int i=0; i<8; i++){
            std::cout << 8-i << '|';
            for(int j=0; j<8; j++){
                if(game1.getSquareAt(j, 7-i ).getHasPiece()){
                    std::cout << game1.getSquareAt(j, 7-i ).getPiece()->getLabel();
                    //cout << "1";
                }
                else{
                    std::cout << ".";
                }
            }
            std::cout << std::endl ;
    }
    std::cout << " |--------" << std::endl;
    std::cout << " |abcdefgh" << std::endl;
}

cmove translate(std::string input, game game1){

    cmove output;
    char abc[]="abcdefgh";
    char s123[]="12345678";



    output.setStartPos(game1.getSquareAt(strchr(abc, input.at(1))-abc, strchr(s123, input.at(2))-s123 )) ;
    output.setEndPos(game1.getSquareAt(strchr(abc, input.at(3))-abc, strchr(s123, input.at(4))-s123 )) ;
    output.setPiece(output.getStartPos().getPiece());

/*
    std::cout << "string search start : " << strchr(abc, input.at(1))-abc << " " << strchr(s123, input.at(2))-s123  << std::endl;
    std::cout << "string search start : " << strchr(abc, input.at(3))-abc << " " << strchr(s123, input.at(4))-s123  << std::endl;
    std::cout << "trans game start    : " << game1.getSquareAt(strchr(abc, input.at(1))-abc, strchr(s123, input.at(2))-s123 ).getPosX() << " " << game1.getSquareAt(strchr(abc, input.at(1))-abc, strchr(s123, input.at(2))-s123 ).getPosY()  << std::endl;
    std::cout << "trans game end      : " << game1.getSquareAt(strchr(abc, input.at(3))-abc, strchr(s123, input.at(4))-s123 ).getPosX() << " " << game1.getSquareAt(strchr(abc, input.at(3))-abc, strchr(s123, input.at(4))-s123 ).getPosY()  << std::endl;
    std::cout << "trans move startpos : " << output.getStartPos().getPosX() << " " << output.getStartPos().getPosY() << std ::endl;
    std::cout << "trans move endpos   : " << output.getEndPos().getPosX() << " " << output.getEndPos().getPosY() << std ::endl;
*/



    return output;
}



