//#include <iostream>
//#include <fstream>
//
//enum MAX_SIZE_CONSTANTS
//{
//	MAX_SIZE_CITY_NAME = 63,
//	MAX_SIZE_DISTRICT = 20
//};
//
//struct City
//{
//	char cityName[MAX_SIZE_CITY_NAME];
//	int population = 0;
//};
//
//struct District
//{
//	City cities[MAX_SIZE_DISTRICT];
//	int currCities = 0;
//};
//
//void saveDistrict(std::ofstream& fileOut, const District& district)
//{
//	for (int i = 0; i < district.currCities; i++)
//	{
//		fileOut << district.cities[i].cityName << " " << district.cities[i].population << std::endl;;
//	}
//}
//
//void sortCitiesByPopulation(District& district)
//{
//	int populationsArr[MAX_SIZE_DISTRICT] = {};
//	for (int i = 0; i < district.currCities; i++)
//	{
//		populationsArr[i] = district.cities[i].population;
//	}
//
//	int minIdx = 0;
//	for (int i = 0; i < district.currCities - 1; i++)
//	{
//		minIdx = i;
//		for (int j = i + 1; j < district.currCities; j++)
//		{
//			if (district.cities[j].population < district.cities[minIdx].population)
//			{
//				minIdx = j;
//			}
//		}
//
//		if (minIdx != i)
//		{
//			City temp = district.cities[i];
//			district.cities[i] = district.cities[minIdx];
//			district.cities[minIdx] = temp;
//		}
//	}
//}
//
//void readDistrict(std::ifstream& fileIn, District& district, const char* fileName)
//{
//	while (!fileIn.eof())
//	{
//		fileIn >> district.cities[district.currCities].cityName
//			   >> district.cities[district.currCities].population;
//		
//		district.currCities++;
//	}
//
//	sortCitiesByPopulation(district);
//	
//	std::ofstream fileOut(fileName);
//	if (!fileOut.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return;
//	}
//
//	saveDistrict(fileOut, district);
//}
//
//int main()
//{
//	std::ifstream fileIn("06_district.txt");
//	District district;
//	const char* fileName = "06_sorted_district.txt";
//
//	readDistrict(fileIn, district, fileName);
//
//	return 0;
//}
