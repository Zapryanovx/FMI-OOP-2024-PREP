#include "Sphinx.h"

int Sphinx::fightWith(const Creature* other) const
{
	return other->fightWithSphinx(this);
}

int Sphinx::fightWithMinotaur(const Minotaur* other) const
{
	return -1;
}

int Sphinx::fightWithCentaur(const Centaur* other) const
{
	return 1;
}

int Sphinx::fightWithSphinx(const Sphinx* other) const
{
	return 0;
}

Creature* Sphinx::clone() const
{
	return new Sphinx(*this);
}