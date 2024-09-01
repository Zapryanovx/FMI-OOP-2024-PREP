#pragma once
#include <iostream>

class Minotaur;
class Centaur;
class Sphinx;

class Creature
{
public:
	Creature() = default;
	virtual ~Creature() = default;

	virtual int fightWith(const Creature* other) const = 0;
	virtual int fightWithMinotaur(const Minotaur* other) const = 0;
	virtual int fightWithCentaur(const Centaur* other) const = 0;
	virtual int fightWithSphinx(const Sphinx* other) const = 0;

	virtual Creature* clone() const = 0;
		 
};

