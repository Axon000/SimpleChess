#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "game.h"
#include "move.h"


class pawn : public piece
{
    public:
        pawn();
        virtual ~pawn();
        bool isMoveOk(game game1, move move1);
    protected:
    private:
};

#endif // PAWN_H
