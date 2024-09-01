#include "CreatureContainer.h"
#include "Minotaur.h"
#include "Centaur.h"
#include "Sphinx.h"

int main()
{

	CreatureContainer container;
	
	Minotaur m;
	Centaur c;
	Sphinx s;

	container.addCreature(m);
	container.addCreature(c);
	container.addCreature(c);
	container.addCreature(s);
	container.addCreature(s);
	container.addCreature(s);

	std::cout << container.fight(0) << std::endl;
	
	container.removeCreature(3);

	std::cout << container.fight(0) << std::endl;
	std::cout << container.fight(1) << std::endl;
	std::cout << container.fight(3) << std::endl;


	return 0;
}