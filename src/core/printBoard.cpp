#include <iostream>
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
