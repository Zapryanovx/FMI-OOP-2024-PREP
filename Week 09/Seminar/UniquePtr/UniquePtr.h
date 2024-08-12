#include <iostream>
#pragma once

struct A
{
	int x;
	int y;
};

class UniquePtr
{
public:
	UniquePtr() = default;
	UniquePtr(A* arg);
	
	//пойнтърът трябва да е уникален, тоест да няма друг, който сочи към същото място
	UniquePtr(const UniquePtr& other) = delete;
	UniquePtr& operator=(const UniquePtr& other) = delete;

	A& operator*();
	const A& operator*() const;

	A* operator->();
	const A* operator->() const;

	A* get();

	void reset(A* nPtr);
	A* release();

	UniquePtr(UniquePtr&& other) noexcept;
	UniquePtr& operator=(UniquePtr&& other) noexcept;

	~UniquePtr();

private:
	
	A* ptr = nullptr;

	void moveFrom(UniquePtr&& other);
	void free();

};

