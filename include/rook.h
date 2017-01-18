#ifndef ROOK_H
#define ROOK_H

#include "piece.h"



class rook : public piece
{
    public:
        rook();
        virtual ~rook();
        virtual bool isMoveOk(game* g, cmove* m) const;
    protected:
    private:
};

#endif // ROOK_H
