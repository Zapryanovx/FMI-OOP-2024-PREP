////Задача 2
////От стандартния вход се прочитат три числа.
////Запишете във файл "result.txt" сумата и произведението им.
////След приключване на програмата в result.txt са записани само сумата и произведението на въведените числа
////(ако преди това е имало друга информация, тя се затрива).
////
////Да се напише функция, която чете от файла result.txt 
////двете записани числа и извежда разликата им на стандартния изхо
//// 
//
//#include <iostream>
//#include <fstream>
//
//struct Triplet
//{
//	int a;
//	int b;
//	int c;
//
//}triplet; 
//
//void readTriplet(Triplet& triplet)
//{
//	std::cin >> triplet.a;
//	std::cin >> triplet.b;
//	std::cin >> triplet.c;
//}
//
//void saveSumInFile(std::ofstream& fileOutput, const int a, const int b, const int c)
//{
//	if (!fileOutput.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return;
//	}
//	fileOutput << a + b + c << " ";
//}
//
//void saveMulInFile(std::ofstream& fileOutput, const int a, const int b, const int c)
//{
//	if (!fileOutput.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return;
//	}
//	fileOutput << a * b * c;
//}
//
//void saveDataInFile(std::ofstream& fileOutput, const int a, const int b, const int c)
//{
//	if (!fileOutput.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return;
//	}
//	saveSumInFile(fileOutput, a, b, c);
//	saveMulInFile(fileOutput, a, b, c);
//	fileOutput.close();
//}
//
//int getDiffOfSumAndMul(std::ifstream& fileInput)
//{
//	if (!fileInput.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return -1;
//	}
//
//	int sum = 0, mul = 0;
//	fileInput >> sum >> mul;
//	fileInput.close();
//
//	return sum - mul;
//}
//
//
//int main()
//{
//	readTriplet(triplet);
//
//	std::ofstream fileOutput("results.txt");
//	saveDataInFile(fileOutput, triplet.a, triplet.b, triplet.c);
//
//	std::ifstream fileInput("results.txt");
//	std::cout << getDiffOfSumAndMul(fileInput);
//
//	return 0;
//}