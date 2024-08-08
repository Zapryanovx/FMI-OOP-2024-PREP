#pragma once

class StringPool
{
public:
	StringPool();
	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);
	StringPool(const StringPool& other) = delete;
	StringPool& operator=(const StringPool& other) = delete;
	~StringPool();

private:
	unsigned allocatedNewString(const char* str);
	void resize(unsigned newCap);
	int findAllocatedString(const char* str) const;

	void removeRecord(unsigned index);

	//ще направим масив от структури, в които ще пазим съдържанието 
	//и броя на срещанията на даден string
	struct StringRecord
	{
		char* str = nullptr;
		unsigned refCount = 0;
	};

	StringRecord* stringRecords;
	size_t stringCount = 0;
	size_t stringCapacity = 0;
};

