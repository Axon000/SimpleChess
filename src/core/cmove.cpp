#include "cmove.h"
#include "square.h"
#include "piece.h"

cmove::cmove()
{
    //ctor
}


cmove::~cmove()
{
    //dtor
}


square cmove::getStartPos() { return m_startPos; }
void cmove::setStartPos(square val) { m_startPos = val; }
square cmove::getEndPos() { return m_endPos; }
void cmove::setEndPos(square val) { m_endPos = val; }
std::string cmove::getCode() { return m_code; }
void cmove::setCode(std::string val) { m_code = val; }
piece* cmove::getPiece() { return m_piece; }
void cmove::setPiece(piece* val) { m_piece = val; }
