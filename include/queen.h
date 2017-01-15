#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"


class queen : public piece
{
    public:
        queen();
        virtual ~queen();
        virtual bool isMoveOk() const;
    protected:
    private:
};

#endif // QUEEN_H
