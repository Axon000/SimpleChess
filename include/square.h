#ifndef SQUARE_H
#define SQUARE_H

#include "piece.h"

class square
{
    public:
        square();
        virtual ~square();
        bool getHasPiece();
        void setHasPiece(bool val);
        piece* getPiece();
        void setPiece(piece* val);
        void setPosX(int val);
        int getPosX();
        void setPosY(int val);
        int getPosY();

    protected:
    private:
        bool m_hasPiece;
        piece *m_piece;
        int m_posX;
        int m_posY;
        //enum color{White, Black};
};

#endif // SQUARE_H
