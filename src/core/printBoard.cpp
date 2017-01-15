#include <iostream>
#include "game.h"
#include "square.h"

void printBoard(game game1){

    square sqr;

    for(int i=0; i<8; i++){
            std::cout << 8-i << '|';
            for(int j=0; j<8; j++){
                sqr = game1.getSquareAt(j, 7-i );
                if(sqr.getHasPiece()){
                    std::cout << sqr.getPiece().getLabel();
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
