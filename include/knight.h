#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "game.h"
#include "move.h"


class knight : public piece
{
    public:
        knight();
        virtual ~knight();
        bool isMoveOk(game game1, move move1);
    protected:
    private:
};

#endif // KNIGHT_H
