#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned n, bool(*incl)(unsigned n)): DynamicSet(n)
{
	fillSet(incl);
}

void SetByCriteria::fillSet(bool(*criteria)(unsigned n))
{
	removeAll();

	size_t range = getN();
	for (int i = 0; i < range; i++)
	{
		if (criteria(i))
		{
			add(i);
		}
	}
}

void SetByCriteria::setInclude(bool(*incl)(unsigned n))
{
	fillSet(incl);
}