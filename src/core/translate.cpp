#include <iostream>
#include <string>
#include <cstring>
#include "translate.h"
#include "game.h"


move translate(std::string input, game game1){

    move output;
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
