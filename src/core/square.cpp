#include <iostream>
#include "square.h"

using namespace std;

square::square()
{
    //ctor
    m_hasPiece = 0;
}

square::~square()
{
    //dtor
}


bool square::getHasPiece() { return m_hasPiece; }
void square::setHasPiece(bool val) { m_hasPiece = val; }
piece* square::getPiece() { return m_piece; }
void square::setPiece(piece* val){ m_piece = val; }
void square::setPosX(int val) { m_posX = val; }
int square::getPosX() { return m_posX; }
void square::setPosY(int val) { m_posY = val; }
int square::getPosY() { return m_posY; }
