#include "FigureFactory.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"

Figure* FigureFactory::createFigure(bool isWhite, FigureType type) 
{	
	switch (type)
	{
		case KingFigure:
			return new King(isWhite);
		case QueenFigure:
			return new Queen(isWhite);
		case KnightFigure:
			return new Knight(isWhite);
		case BishopFigure:
			return new Bishop(isWhite);
		case PawnFigure:
			return new Pawn(isWhite);
		case RookFigure:
			return new Rook(isWhite);
		default:
			return nullptr;
	}
}