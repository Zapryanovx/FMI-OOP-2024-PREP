#pragma once
#include "FigureBase.h"

class King: public Figure
{
public:
	King(bool isWhite);

	bool canBeMoved(size_t currentX, size_t currentY, size_t distX, size_t distY) const override;
	void print() const override;
};

