#ifndef KING_H
#define KING_H

#include "piece.h"



class king : public piece
{
    public:
        king();
        virtual ~king();
        virtual bool isMoveOk() const;
    protected:
    private:
};

#endif // KING_H
