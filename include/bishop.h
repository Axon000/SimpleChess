#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "game.h"
#include "move.h"


class bishop : public piece
{
    public:
        bishop();
        virtual ~bishop();
        bool isMoveOk(game game1, move move1);
    protected:
    private:
};

#endif // BISHOP_H
