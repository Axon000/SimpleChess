#ifndef GAME_H
#define GAME_H
#include <vector>
#include "move.h"
#include "square.h"
#include "rook.h"
#include "piece.h"





class game
{
    public:
        game();
        virtual ~game();
        std::vector<move> getMoveList();
        void setMoveList(std::vector<move> val);
        square getSquareAt(int posX, int posY);
        void castMove(move nextMove);
        void setStartPosition();
        bool checkMove(piece const& p);


    protected:
    private:
        std::vector<move> m_moveList;
        square m_board[8][8];
        rook m_rw[2];
        rook m_rb[2];
};

#endif // GAME_H
