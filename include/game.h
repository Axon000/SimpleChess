#ifndef GAME_H
#define GAME_H
#include <vector>
#include "cmove.h"
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
        std::vector<cmove> getMoveList();
        void setMoveList(std::vector<cmove> val);
        square getSquareAt(int posX, int posY);
        void castMove(cmove nextcmove);
        void setStartPosition();
        bool checkMove(piece const& p, cmove m);
        bool getWhiteToPlay();
        void setWhiteToPlay(bool val);
        void addMove(cmove m);
        square getPlayerKingSquare();



    protected:
    private:
        std::vector<cmove> m_moveList;
        square m_board[8][8];
        bool m_whitetoplay;
        bool m_whiteHasRooked;
        bool m_blackHasRooked;
        bool m_kingChecked;
        std::vector<rook*> m_rw;
        std::vector<rook*> m_rb;
        std::vector<pawn*> m_pw;
        std::vector<pawn*> m_pb;
        std::vector<bishop*> m_bw;
        std::vector<bishop*> m_bb;
        std::vector<knight*> m_nw;
        std::vector<knight*> m_nb;
        std::vector<queen*> m_qw;
        std::vector<queen*> m_qb;
        king* m_kw;
        king* m_kb;
};

#endif // GAME_H
