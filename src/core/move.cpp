#include "move.h"
#include "square.h"
#include "piece.h"

move::move()
{
    //ctor
}


move::~move()
{
    //dtor
}


square move::getStartPos() { return m_startPos; }
void move::setStartPos(square val) { m_startPos = val; }
square move::getEndPos() { return m_endPos; }
void move::setEndPos(square val) { m_endPos = val; }
std::string move::getCode() { return m_code; }
void move::setCode(std::string val) { m_code = val; }
piece* move::getPiece() { return m_piece; }
void move::setPiece(piece* val) { m_piece = val; }
