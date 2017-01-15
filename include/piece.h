#ifndef PIECE_H
#define PIECE_H

//#include "square.h"


class piece
{
    public:
        piece();
        virtual ~piece();
        /*
        int getPosX();
        void setPosX(int val);
        int getPosY();
        void setPosY(int val);
        */
        //square getSquare();
        //void setSquare(square sqr);

        char getLabel();
        void setLabel(char lab);
        virtual bool isMoveOk() const;
    protected:
    private:
        //int m_posX;
        //int m_posY;
        //square m_square;
        char m_label;
};

#endif // PIECE_H
