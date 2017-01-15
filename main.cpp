#include <iostream>
#include "game.h"
#include "move.h"
#include "translate.h"
#include "printBoard.h"

using namespace std;

int main()
{

    game game1;
    string input;
    move nextmove;

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
