//#include <iostream>
//#include <fstream>
//
//enum MAX_SIZE_CONSTANTS
//{
//	MAX_SIZE_RELATION = 25,
//};
//
//struct Pair
//{
//	int x;
//	int y;
//
//};
//
//struct Relation
//{
//	Pair pairs[MAX_SIZE_CONSTANTS::MAX_SIZE_RELATION];
//	int currSize = 0;
//};
//
//void readRelationFromFile(std::ifstream& fileIn, Relation& relation)
//{
//	while (!fileIn.eof())
//	{
//		fileIn >> relation.pairs[relation.currSize].x;
//		fileIn >> relation.pairs[relation.currSize++].y;
//	}
//	fileIn.close();
//}
//
//void addPairToRelation(Relation& relation, const Pair& pair)
//{
//	if (relation.currSize >= MAX_SIZE_CONSTANTS::MAX_SIZE_RELATION)
//	{
//		std::cout << "[ERROR] Max size reached.";
//		return;
//	}
//
//	relation.pairs[relation.currSize].x = pair.x;
//	relation.pairs[relation.currSize].y = pair.y;
//	relation.currSize++;
//}
//
//void saveRelationToFile(std::ofstream& fileOut, Relation& relation)
//{	
//	for(int i  = 0; i < relation.currSize; i++)
//	{
//		fileOut << relation.pairs[i].x << " " << relation.pairs[i].y << std::endl;
//	}
//	fileOut.close();
//
//}
//
//int main()
//{
//	std::ifstream fileIn("05_relation.txt");
//	if (!fileIn.is_open())
//	{
//		return -1;
//	}
//
//	Relation relation;
//	readRelationFromFile(fileIn, relation);
//	std:: cout << relation.pairs[1].x << " " << relation.pairs[1].y;
//
//	std::ofstream fileOut("05_relation.txt");
//	if (!fileOut.is_open())
//	{
//		return -1;
//	}
//
//	Pair pair;
//	pair.x = 9;
//	pair.y = 10;
//
//	addPairToRelation(relation, pair);
//	saveRelationToFile(fileOut, relation);
//
//	return 0;
//}