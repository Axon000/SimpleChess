#ifndef ROOK_H
#define ROOK_H

#include "piece.h"



class rook : public piece
{
    public:
        rook();
        virtual ~rook();
        virtual bool isMoveOk() const;
    protected:
    private:
};

#endif // ROOK_H
