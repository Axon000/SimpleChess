#ifndef MOVE_H
#define MOVE_H
#include "square.h"
#include "piece.h"
#include <string>

class move
{
    public:
        move();
        virtual ~move();
        square getStartPos();
        void setStartPos(square val);
        square getEndPos();
        void setEndPos(square val);
        std::string getCode();
        void setCode(std::string val);
        piece* getPiece();
        void setPiece(piece* val);
    protected:
    private:
        square m_startPos;
        square m_endPos;
        std::string m_code;
        piece* m_piece;
};

#endif // MOVE_H
