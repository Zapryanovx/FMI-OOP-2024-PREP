//#include <iostream>
//#include <fstream>
//
//struct pair
//{
//	int x;
//	int y;
//};
//
//const int MAX_SIZE_PAIRS = 25;
//struct relation
//{
//	pair pairs[MAX_SIZE_PAIRS];
//	int currentPairsCount = 0;
//};
//
//pair createPair(int x, int y)
//{
//	pair pair;
//	pair.x = x;
//	pair.y = y;
//
//	return pair;
//}
//
//void initPair(pair& toInit, int x, int y)
//{
//	toInit.x = x;
//	toInit.y = y;
//}
//
//pair readPairFromFile(std::ifstream& inFile)
//{
//	pair pair;
//	if (!inFile.is_open())
//	{
//		std::cout << "[ERROR] File not found";
//		return pair;
//	}
//
//	inFile >> pair.x >> pair.y;
//	return pair;
//}
//
//
//void writePairToFile(std::ofstream& outFile, const pair& toWrite)
//{
//	if (!outFile.is_open())
//	{
//		std::cout << "[ERROR] File not found";
//		return;
//	}
//
//	pair pair; 
//	outFile << toWrite.x << toWrite.y;
//}
//
//bool addPair(relation& arg, pair& toInsert)
//{
//	if (arg.currentPairsCount >= 25)
//	{
//		return 0;
//	}
//
//	arg.pairs[arg.currentPairsCount++] = toInsert;
//	return 1;
//}
//
//bool writeRelation(const relation& arg, const char* filePath)
//{
//	std::ofstream fileOut(filePath);
//	for (int i = 0; i < arg.currentPairsCount; i++)
//	{
//		fileOut << arg.pairs[i].x << " " << arg.pairs[i].y;
//	}
//}
//
//bool readRelation(relation& arg, const char* filepath)
//{
//	arg.currentPairsCount = 0;
//	
//	std::ifstream fileIn(filepath);
//	if (!fileIn.is_open())
//	{
//		std::cout << "[ERROR] File not found";
//		return 0;
//	}
//
//	while (!fileIn.eof())
//	{
//		pair pair;
//		fileIn >> pair.x >> pair.y;
//		arg.currentPairsCount++;
//	}
//
//	return 1;
//}
//
//int main()
//{
//	//createPair(2, 3);
//
//
//	return 0;
//}