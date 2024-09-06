#pragma once
#include "FigureBase.h"
#include "ConfigEnums.h"

class FigureFactory
{
public:
	static Figure* createFigure(bool isWhite, FigureType type);
};

