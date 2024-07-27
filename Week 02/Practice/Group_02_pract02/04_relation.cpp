#include <iostream>
#include <fstream>

struct Pair
{
 	unsigned int x;
	unsigned int y;
};

struct Relation
{
	Pair pairs[25];
	int currentPairsCount = 0;
};

void initPair(Pair& Pair, const unsigned x, const unsigned y)
{
	Pair.x = x;
	Pair.y = y;
}


void createPair(Pair& pair)
{
	int x = 0, y = 0;
	std::cin >> x >> y;

	if (!(x >= 0 && y >= 0))
	{
		std::cout << "[ERROR] Invalid values in (x,y).";
	}
	initPair(pair, x, y);
}

void writeRelationToFile(const Relation& relation, const char* fileName)
{
	std::ofstream fileOut(fileName);

	if (!fileOut.is_open())
	{
		std::cout << "[ERROR] File not found.";
		return;
	}

	for (int i = 0; i < relation.currentPairsCount; i++)
	{
		fileOut << relation.pairs[i].x << " " << relation.pairs[i].y;
	}

	fileOut.close();
}

void readRelationFromFile(Relation& relation, const char* fileName)
{
	std::ifstream fileIn(fileName);

	if (!fileIn.is_open())
	{
		std::cout << "[ERROR] File not found.";
		return;
	}

	for (int i = 0; i < relation.currentPairsCount; i++)
	{
		fileIn >> relation.pairs[i].x >> relation.pairs[i].y;
	}

	std::cout << relation.pairs[0].x << " " << relation.pairs[0].y << std::endl;

	fileIn.close();
}


void addPairToRelation(Relation& relation, const Pair& pair)
{
	if (relation.currentPairsCount >= 25)
	{
		std::cout << "[ERROR] Max pairs reached." << std::endl;
		return;
	}

	relation.pairs[relation.currentPairsCount++] = pair;
}

void makePair(const int x, const int y)
{
	if (!(x >= 0 && y >= 0))
	{
		std::cout << "[ERROR] Invalid values in (x,y).";
	}
	Pair pair;
	initPair(pair, x, y);
}

int main()
{
	Pair pair;
	createPair(pair);

	Relation relation;
	addPairToRelation(relation, pair);

	writeRelationToFile(relation, "04_relation.txt");
	readRelationFromFile(relation, "04_relation.txt");

	makePair(3, 4);

	return 0;
}
