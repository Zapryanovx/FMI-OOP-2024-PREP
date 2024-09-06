#include "Pawn.h"

Pawn::Pawn(bool isWhite): Figure(isWhite, FigureType::PawnFigure) {}

bool Pawn::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const 
{
	if (getIsWhite())
	{
		return currentY - 1 == destY && std::abs((int)currentX - (int)destX) <= 1;
	}

	return currentY + 1 == destY && std::abs((int)currentX - (int)destX) <= 1;
	
}

void Pawn::print() const
{
	if (getIsWhite())
	{
		std::cout << 'P';
	}

	else
	{
		std::cout << 'p';
	}
}

