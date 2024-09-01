#include "Minotaur.h"

int Minotaur::fightWith(const Creature* other) const
{
	return other->fightWithMinotaur(this);
}

int Minotaur::fightWithMinotaur(const Minotaur* other) const
{
	return 0;
}

int Minotaur::fightWithCentaur(const Centaur* other) const
{
	return -1;
}

int Minotaur::fightWithSphinx(const Sphinx* other) const
{
	return 1;
}

Creature* Minotaur::clone() const
{
	return new Minotaur(*this);
}

