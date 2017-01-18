#ifndef PAWN_H
#define PAWN_H

#include "piece.h"



class pawn : public piece
{
    public:
        pawn();
        virtual ~pawn();
        virtual bool isMoveOk(game* g, cmove* m) const;
    protected:
    private:
};

#endif // PAWN_H
