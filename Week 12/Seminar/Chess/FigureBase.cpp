#include "FigureBase.h"

Figure::Figure(bool isWhite, FigureType type): isWhite(isWhite), type(type) {}

bool Figure::getIsWhite() const
{
	return isWhite;
}

FigureType Figure::getFigureType() const
{
	return type;
}

