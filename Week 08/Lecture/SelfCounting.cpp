#include "SelfCounting.h"

//статичните член-данни трябва да се инициализират тук
//(освен ако не са константни)
unsigned SelfCounting::liveObjectsCount = 0;
unsigned SelfCounting::createdCount = 0;

SelfCounting::SelfCounting(): SelfCounting(42){} //42 is random (initialization list)

//създаваме нов обект + имаме нов жив обект 
SelfCounting::SelfCounting(int val): const_val(val)
{
	liveObjectsCount++;
	createdCount++;
}

//създаваме нов обект + имаме нов жив обект 
SelfCounting::SelfCounting(const SelfCounting& other): const_val(other.const_val) // (initialization list)
{
	liveObjectsCount++;
	createdCount++;
}

//унищожава се един наш жив обект 
SelfCounting::~SelfCounting()
{
	liveObjectsCount--;
}

unsigned SelfCounting::getLiveObjectsCount()
{
	return liveObjectsCount;
}

unsigned SelfCounting::getCreatedCount()
{
	return createdCount;
}
