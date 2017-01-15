#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"



class bishop : public piece
{
    public:
        bishop();
        virtual ~bishop();
        virtual bool isMoveOk() const;
    protected:
    private:
};

#endif // BISHOP_H
