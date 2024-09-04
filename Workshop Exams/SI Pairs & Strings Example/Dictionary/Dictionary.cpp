#include "Dictionary.h"
#pragma warning(disable: 4996)

void Dictionary::Word::setWord(const char* word)
{
	this->word = new char[std::strlen(word) + 1];
	std::strcpy(this->word, word);
}

void Dictionary::Word::setDesc(const char* desc)
{
	this->desc = new char[std::strlen(desc) + 1];
	std::strcpy(this->desc, desc);
}

void Dictionary::Word::free()
{
	delete[] word;
	word = nullptr;

	delete[] desc;
	desc = nullptr;
}

void Dictionary::copyFrom(const Dictionary& other)
{
	size = other.size;
	capacity = other.capacity;

	words = new Word[capacity];
	for (int i = 0; i < size; i++)
	{
		words[i].setWord(other.words[i].word);
		words[i].setDesc(other.words[i].desc);
	}

}

void Dictionary::moveFrom(Dictionary&& other)
{
	words = other.words;
	other.words = nullptr;

	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity = 0;
}

void Dictionary::free()
{
	delete[] words;
}

void Dictionary::resize(size_t newCap)
{
	Word* newWords = new Word[newCap];

	for (int i = 0; i < size; i++)
	{
		newWords[i] = words[i];
	}

	delete[] words;
	words = newWords;
	newWords = nullptr;

	capacity = newCap;
}

size_t Dictionary::find(const char* word, bool& isFound) const
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int cmpRes = std::strcmp(word, words[mid].word);

		if (cmpRes == 0)
		{
			isFound = true;
			return mid;
		}

		if (cmpRes == -1)
		{
			right = mid - 1;
		}

		if (cmpRes == 1)
		{
			left = mid + 1;
		}

	}
	
	return left;
}

void Dictionary::shiftLeft(int from)
{
	for (int i = from; i < size - 1; i++)
	{
		words[i] = words[i + 1];
	}
}

void Dictionary::shiftRight(int from)
{
	for (int i = size - 1; i >= from; i--)
	{
		words[i + 1] = words[i];
	}
}

Dictionary::Dictionary()
{
	size = 0;
	capacity = 8;
	words = new Word[capacity];
}

Dictionary::Dictionary(const Dictionary& other)
{
	copyFrom(other);
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Dictionary::Dictionary(Dictionary&& other) noexcept
{
	moveFrom(std::move(other));
}

Dictionary& Dictionary::operator=(Dictionary&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Dictionary::~Dictionary()
{
	free();
}

void Dictionary::add(const char* word, const char* desc)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	bool isFound = false;
	size_t pos = find(word, isFound);
	if (isFound)
	{
		size_t newSize = std::strlen(words[pos].desc) + std::strlen(desc) + 1;
		char* newDesc = new char[newSize];
		std::strcpy(newDesc, words[pos].desc);
		std::strcat(newDesc, desc);
		delete[] words[pos].desc;
		
		words[pos].setDesc(newDesc);

	}
	else
	{
		shiftRight(pos);
		words[pos].setWord(word);
		words[pos].setDesc(desc);

		size++;
	}
}

void Dictionary::remove(const char* word)
{
	bool isFound = false;
	size_t pos = find(word, isFound);

	if (!isFound)
	{
		return;
	}

	words[pos].free();
	shiftLeft(pos);
	
	size--;
}

void Dictionary::print() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[Word]: " << words[i].word << std::endl;
		std::cout << "[Description]: " << words[i].desc << std::endl;

		if (i != size - 1)
		{
			std::cout << "------------------------------------" << std::endl;
		}
	}
}

const char* Dictionary::operator()(const char* word)
{
	bool isFound = false;
	size_t pos = find(word, isFound);

	if (!isFound)
	{
		throw std::invalid_argument("Word not found.");
	}

	return words[pos].desc;
}

Dictionary& Dictionary::operator+=(const Dictionary& other)
{
	for (int i = 0; i < other.size; i++)
	{
		add(other.words[i].word, other.words[i].desc);
	}

	return *this;
}

Dictionary operator+(const Dictionary& lhs, const Dictionary& rhs)
{
	Dictionary res(lhs);
	res += rhs;
	return res;
}