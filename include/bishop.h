#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"


class bishop : public piece
{
    public:
        bishop();
        virtual ~bishop();
        virtual bool isMoveOk(game* g, cmove* m) const;
    protected:
    private:
};

#endif // BISHOP_H
