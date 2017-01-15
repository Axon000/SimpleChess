#ifndef GAME_H
#define GAME_H
#include <vector>
#include "move.h"
#include "square.h"
#include "rook.h"
#include "pawn.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
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
        bool checkMove(piece const& p, move m);


    protected:
    private:
        std::vector<move> m_moveList;
        square m_board[8][8];
        rook m_rw[2];
        rook m_rb[2];
        pawn m_pw[8];
        pawn m_pb[8];
        bishop m_bw[2];
        bishop m_bb[2];
        knight m_nw[2];
        knight m_nb[2];
        king m_kw;
        king m_kb;
        queen m_qw;
        queen m_qb;
};

#endif // GAME_H
