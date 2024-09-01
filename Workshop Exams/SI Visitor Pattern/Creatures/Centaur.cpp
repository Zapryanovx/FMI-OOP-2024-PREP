#include "Centaur.h"

int Centaur::fightWith(const Creature* other) const 
{
	return other->fightWithCentaur(this);
}

int Centaur::fightWithMinotaur(const Minotaur* other) const
{
	return 1;
}

int Centaur::fightWithCentaur(const Centaur* other) const
{
	return 0;
}

int Centaur::fightWithSphinx(const Sphinx* other) const
{
	return -1;
}

Creature* Centaur::clone() const
{
	return new Centaur(*this);
}

