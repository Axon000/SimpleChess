#include <iostream>
#include "piece.h"


piece::piece()
{
    //ctor
}

piece::~piece()
{
    //dtor
}


char piece::getLabel(){ return m_label; }
void piece::setLabel(char lab){ m_label = lab; }


