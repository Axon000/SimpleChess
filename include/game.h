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
        std::vector<rook*> m_rw;
        std::vector<rook*> m_rb;
        std::vector<pawn*> m_pw;
        std::vector<pawn*> m_pb;
        std::vector<bishop*> m_bw;
        std::vector<bishop*> m_bb;
        std::vector<knight*> m_nw;
        std::vector<knight*> m_nb;
        std::vector<king*> m_kw;
        std::vector<king*> m_kb;
        std::vector<queen*> m_qw;
        std::vector<queen*> m_qb;
};

#endif // GAME_H
