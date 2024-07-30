//#include <iostream>
//#include <fstream>
//
//int getRowsOfMatrix(std::ifstream& fileIn)
//{
//	int counter = 0;
//	while(!fileIn.eof())
//	{
//		char delim = fileIn.get();
//		if (delim == '|')
//		{
//			counter++;
//		}
//	}
//
//	fileIn.clear();
//	fileIn.seekg(0, std::ios::beg);
//	return counter + 1;
//}
//
//int getColsOfMatrix(std::ifstream& fileIn)
//{
//	int counter = 0;
//	char delim = ' ';
//	while (fileIn.get(delim) && delim != '|')
//	{
//		if (delim == ',')
//		{
//			counter++;
//		}
//	}
//
//	fileIn.clear();
//	fileIn.seekg(0, std::ios::beg);
//	return counter + 1;
//}
//
//bool isMulPossible(unsigned colsFirst, unsigned rowsSecond)
//{
//	return colsFirst == rowsSecond;
//}
//
//int** getMatrix(std::ifstream& fileIn, unsigned rows, unsigned cols)
//{
//
//	int** ptrMatrix = new int* [rows];
//	for (unsigned i = 0; i < rows; i++) 
//	{
//		ptrMatrix[i] = new int[cols];
//	}
//	
//	unsigned row = 0;
//	unsigned col = 0;
//
//	int value = 0;
//	while (fileIn >> value)
//	{
//		ptrMatrix[row][col++] = value;
//		if (col >= cols)
//		{
//			col = 0;
//			row++;
//		}
//		fileIn.get();
//	}
//
//	return ptrMatrix;
//}
//
//int** mulMatrixes(std::ofstream& fileRes, int** ptrFirst, int** ptrSecond, unsigned rowsFirst, unsigned colsFirst, 
//				unsigned rowsSecond, unsigned colsSecond, unsigned rowsRes, unsigned colsRes)
//{
//	if (!isMulPossible(colsFirst, rowsSecond) || !ptrFirst || !ptrSecond)
//	{
//		return nullptr;
//	}
//
//	int** ptrRes = new int* [rowsRes];
//	for (int rowRes = 0; rowRes < rowsRes; rowRes++)
//	{
//		ptrRes[rowRes] = new int[colsRes];
//	}
//
//	for (unsigned rowRes = 0; rowRes < rowsRes; rowRes++)
//	{
//		for (unsigned colRes = 0; colRes < colsRes; colRes++)
//		{
//			ptrRes[rowRes][colRes] = 0;
//			for (unsigned k = 0; k < colsFirst; k++)
//			{
//				ptrRes[rowRes][colRes] += ptrFirst[rowRes][k] * ptrSecond[k][colRes];
//			}
//		}
//	}
//	
//	return ptrRes;
//}
//
//void printMatrix(int** ptrFirst, unsigned rows, unsigned cols)
//{
//	for (unsigned i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			std::cout << ptrFirst[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//void saveResInFile(std::ofstream& fileRes, int** ptrRes, unsigned rowsRes, unsigned colsRes)
//{
//	for (int rowRes = 0; rowRes < rowsRes; rowRes++)
//	{
//		for (int colRes = 0; colRes < colsRes; colRes++)
//		{
//			if (colRes < colsRes - 1)
//			{
//				fileRes << ptrRes[rowRes][colRes] << ",";
//			}
//
//			else
//			{
//				fileRes << ptrRes[rowRes][colRes];
//			}
//		}
//		fileRes << "|";
//	}
//}
//
//void freeMemory(int** ptr, unsigned rows)
//{
//	for (unsigned i = 0; i < rows; i++)
//	{
//		delete[] ptr[i];
//	}
//	delete[] ptr;
//}
//
//int main()
//{
//	std::ifstream fileInFirst("01_first_matrix.txt");
//	std::ifstream fileInSecond("01_second_matrix.txt");
//
//	unsigned rowsFirst = getRowsOfMatrix(fileInFirst);
//	unsigned colsFirst = getColsOfMatrix(fileInFirst);
//	unsigned rowsSecond = getRowsOfMatrix(fileInSecond);
//	unsigned colsSecond = getColsOfMatrix(fileInSecond);
//
//	int** ptrFirst = getMatrix(fileInFirst, rowsFirst, colsFirst);
//	int** ptrSecond = getMatrix(fileInSecond, rowsSecond, colsSecond);
//
//	printMatrix(ptrFirst, rowsFirst, colsSecond);
//	printMatrix(ptrSecond, rowsSecond, colsSecond);
//
//	unsigned rowsRes = rowsFirst;
//	unsigned colsRes = colsSecond;
//
//	std::ofstream fileRes("01_res_matrix.txt");
//	int** ptrRes = mulMatrixes(fileRes, ptrFirst, ptrSecond, rowsFirst, colsFirst, rowsSecond, colsSecond, rowsRes, colsRes);
//	printMatrix(ptrRes, rowsRes, colsRes);
//
//	saveResInFile(fileRes, ptrRes, rowsRes, colsRes);
//
//	freeMemory(ptrFirst, rowsFirst);
//	freeMemory(ptrSecond, rowsSecond);
//	freeMemory(ptrRes, rowsRes);
//
//
//	return 0;
//}