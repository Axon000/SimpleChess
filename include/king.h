#ifndef KING_H
#define KING_H

#include "piece.h"
#include "game.h"
#include "move.h"


class king : public piece
{
    public:
        king();
        virtual ~king();
        bool isMoveOk(game game1, move move1);
    protected:
    private:
};

#endif // KING_H
