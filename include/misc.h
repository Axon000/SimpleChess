#ifndef MISC_H_INCLUDED
#define MISC_H_INCLUDED
#include "cmove.h"
#include "game.h"
#include "square.h"

void printBoard(game game1);

cmove translate(std::string input, game game1);


template<typename T>
int sign(T val){
    return (T(0) < val) - (val < T(0));
}

#endif // MISC_H_INCLUDED
