#pragma once
#include "DynamicSet.h"

class SetByCriteria: private DynamicSet
{
public:
	SetByCriteria(unsigned n, bool(*incl)(unsigned n));
	void setInclude(bool(*incl)(unsigned n));

	// тъй като наследяването е private, потребителят не може да използва 
	// print и contains => трябва някак си да му възвърнем достъпа до тях
	// единият начин е този, като чрез using преместим print и contains
	// в public, другият е да пренапишем функциите 
	//(SetByString е направен по другия начин) 
	using DynamicSet::print;
	using DynamicSet::contains;
private:

	void fillSet(bool(*criteria)(unsigned n));
};

