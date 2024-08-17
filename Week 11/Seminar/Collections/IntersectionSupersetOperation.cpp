#include "IntersectionSupersetOperation.h"

IntersectionSupersetOperation::IntersectionSupersetOperation(const Collection& l, const Collection& r):
	CollectionSupersetOperation(l, r){}

void IntersectionSupersetOperation::add(int arg)
{
	dummy.add(arg);
}

void IntersectionSupersetOperation::remove(int arg)
{
	dummy.remove(arg);
}

size_t IntersectionSupersetOperation::count(int arg) const
{
	return left.count(arg) + right.count(arg) + dummy.count(arg);
}

bool IntersectionSupersetOperation::contains(int arg) const
{
	return left.contains(arg) && right.contains(arg);
}

