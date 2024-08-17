#include "UnionSupersetOperation.h"

UnionSupersetOperation::UnionSupersetOperation(const Collection& l, const Collection& r): CollectionSupersetOperation(l, r){}

void UnionSupersetOperation::add(int arg)
{
	dummy.add(arg);
}

void UnionSupersetOperation::remove(int arg)
{
	dummy.remove(arg);
}

size_t UnionSupersetOperation::count(int arg) const
{
	return left.count(arg) + right.count(arg) + dummy.count(arg);
}

bool UnionSupersetOperation::contains(int arg) const
{
	return left.contains(arg) || right.contains(arg) || dummy.contains(arg);
}