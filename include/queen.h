#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "game.h"
#include "move.h"

class queen : public piece
{
    public:
        queen();
        virtual ~queen();
        bool isMoveOk(game game1, move move1);
    protected:
    private:
};

#endif // QUEEN_H
