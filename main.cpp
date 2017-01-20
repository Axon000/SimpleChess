#include <iostream>
#include "misc.h"
#include "game.h"
#include "cmove.h"


using namespace std;

int main()
{

    game game1;
    string input;
    cmove nextmove;

    printBoard(game1);
    cin >> input;

    while(input != "exit"){
        nextmove = translate(input, game1);
        game1.castMove(nextmove);
        printBoard(game1);
        cin >> input;
    }


    return 0;
}
