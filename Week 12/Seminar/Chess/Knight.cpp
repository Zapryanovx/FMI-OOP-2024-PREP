#include "Knight.h"

Knight::Knight(bool isWhite): Figure(isWhite, FigureType::KnightFigure) {}

bool Knight::canBeMoved(size_t currentX, size_t currentY, size_t destX, size_t destY) const
{
	int xMovement[] = { 1, 1, -1, -1, 2, -2, 2, -2 };
	int yMovement[] = { 2, -2, 2, -2, 1, 1, -1, -1 };

	for (int i = 0; i < 8; i++)
	{
		if (currentX + xMovement[i] == destX
			&& currentY + yMovement[i] == destY)
		{
			return true;
		}
	}

	return false;
}

void Knight::print() const
{
	if (getIsWhite())
	{
		std::cout << 'K';
	}

	else
	{
		std::cout << 'k';
	}
}