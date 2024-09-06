#pragma once
#include <iostream>
#include "ConfigEnums.h"

class Figure
{
	bool isWhite;
	FigureType type;

public:
	Figure(bool isWhite, FigureType type);

	virtual bool canBeMoved(size_t currentX, size_t currentY, size_t distX, size_t distY) const = 0;
	virtual void print() const = 0;

	bool getIsWhite() const;
	FigureType getFigureType() const;

	virtual ~Figure() = default;

};

