#include <iostream>
#include "piece.h"


piece::piece()
{
    //ctor
}

piece::~piece()
{
    //dtor
    //std::cout << "call to destructor" << std::endl;
}

/*
bool piece::isMoveOk() const
{
    std::cout << "call in piece" << std::endl;

    return 1;
}
*/


/*
int piece::getPosX() { return m_posX; }
void piece::setPosX(int val) { m_posX = val; }
int piece::getPosY() { return m_posY; }
void piece::setPosY(int val) { m_posY = val; }
*/
//square piece::getSquare() { return m_square; };
//void piece::setSquare(square sqr) { m_square = sqr; };
char piece::getLabel(){ return m_label; }
void piece::setLabel(char lab){ m_label = lab; }
