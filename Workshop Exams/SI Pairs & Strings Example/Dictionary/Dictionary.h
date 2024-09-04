#pragma once
#include <iostream>

class Dictionary
{
private:
	struct Word
	{
		char* word;
		char* desc;

		void setWord(const char* word);
		void setDesc(const char* desc);
		void free();
	};

	Word* words;
	size_t size;
	size_t capacity;

	void copyFrom(const Dictionary& other);
	void moveFrom(Dictionary&& other);
	void free();

	void resize(size_t newCap);

	size_t find(const char* word, bool& isFound) const;
	void shiftLeft(int from);
	void shiftRight(int from);

public:
	Dictionary();
	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);

	Dictionary(Dictionary&& other) noexcept;
	Dictionary& operator=(Dictionary&& other) noexcept;

	~Dictionary();

	void add(const char* word, const char* desc);
	void remove(const char* word);

	void print() const;
	const char* operator()(const char* word);

	Dictionary& operator+=(const Dictionary& other);

};

Dictionary operator+(const Dictionary& lhs, const Dictionary& rhs);

