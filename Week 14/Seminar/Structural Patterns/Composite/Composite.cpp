#include <iostream>
#include "polymorphic_ptr.hpp"
#include "Vector.hpp"

class FileSystemEntity
{
public:
	virtual size_t getSize() const = 0;
	virtual ~FileSystemEntity() = default;

};


//листата
class File : public FileSystemEntity
{
	size_t size = 0;

public:
	size_t getSize() const
	{
		return size;
	}
};

class Directory : public FileSystemEntity
{
	Vector<polymorphic_ptr<FileSystemEntity>> children;

public:

	//междинни върхове - влизаме все по-навътре, докато не стигнем до листата (файловете)
	//и не вземем размерите им
	size_t getSize() const
	{
		size_t size = 0;
		for (int i = 0; i < children.getSize(); i++)
		{
			size += children[i]->getSize();
		}

		return size;
	}
	

};

int main()
{
	//
}