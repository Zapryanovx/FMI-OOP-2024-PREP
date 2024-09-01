#pragma once
#include "Creature.h"

class Minotaur: public Creature
{
public:
	Minotaur() = default;

	int fightWith(const Creature* other) const override;
	int fightWithMinotaur(const Minotaur* other) const override;
	int fightWithCentaur(const Centaur* other) const override;
	int fightWithSphinx(const Sphinx* other) const override;

	Creature* clone() const override;
};

