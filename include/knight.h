#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"



class knight : public piece
{
    public:
        knight();
        virtual ~knight();
        virtual bool isMoveOk() const;
    protected:
    private:
};

#endif // KNIGHT_H
