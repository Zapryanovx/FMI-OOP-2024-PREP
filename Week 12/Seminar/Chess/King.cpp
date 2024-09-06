#include "King.h"

King::King(bool isWhite) : Figure(isWhite, FigureType::KingFigure){}

bool King::canBeMoved(size_t currentX, size_t currentY, size_t distX, size_t distY) const
{
	return std::abs((int)currentX - (int)distX) <= 1 && std::abs((int)currentY - (int)distY) <= 1;
}

void King::print() const
{
	if (getIsWhite())
	{
		std::cout << "%";
	}

	else
	{
		std::cout << "$";
	}
}