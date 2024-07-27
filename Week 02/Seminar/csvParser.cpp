//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

//Да се напише функция modifyColumn(const char* filePath, const char* columnName, const char* values, char separator) където:
//
//filePath - път към файл във формат.csv
//columnName - колоната, която ще променяме
//values - стойностите, които ще записваме в колоната
//separator - символът, който разделя стойностите записани във values масива.
//Ако стойностите са по - малко от дължината на колоната се записват всички.Ако са повече се записват докато колоната не се напълни.

#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

namespace GlobalConstants
{
	constexpr int FIELD_MAX_SIZE = 30;
	constexpr int MAX_FIELDS_ROW = 10;
	constexpr int ROWS_MAX_SIZE = 300;
	constexpr int BUFFER_SIZE = 256;
	constexpr char SEP = ',';
}

//едно поле е масив от символи, а един ред е масив от полета
typedef char Field[GlobalConstants::FIELD_MAX_SIZE];
typedef Field Row[GlobalConstants::MAX_FIELDS_ROW];

//таблицата ни представлява масив от редове
struct CsvTable
{
	Row rows[GlobalConstants::ROWS_MAX_SIZE];
	size_t rowsCount = 0;
	size_t collsCount = 0;
};

//идея на функцията: разделяме [row] на полета и ги запазваме в [toReturn]
size_t parseRow(const char* row, Row& toReturn)
{
	std::cout << row << std::endl;
	std::stringstream ss(row);
	size_t currentColumnCount = 0;
	while (!ss.eof())
	{

		//взимаме текста до срещането на разделителя ни, след което го запазваме в текущата клетка на [toReturn] 
		//и преминаваме на следващата клетка на [toReturn]
		ss.getline(toReturn[currentColumnCount++], GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::SEP);
	}

	//връщаме броя на колоните
	return currentColumnCount;

}

CsvTable parseFromFile(std::istream& ifs)
{
	CsvTable result;
	char rowStr[GlobalConstants::BUFFER_SIZE];

	while (!ifs.eof())
	{
		//четем ред по ред от файла,
		//като първо запазваме прочетения ред в текущия ред на [result],
		//след което преминаваме на следващия ред на [result]
		ifs.getline(rowStr, GlobalConstants::BUFFER_SIZE, '\n');
		result.collsCount = parseRow(rowStr, result.rows[result.rowsCount++]);
	}

	return result;
}

//ще разширим интерфейса, така че да можем да подаваме
//и име на файл, не само директно поток
CsvTable parseFromFile(const char* fileName)
{
	//nullptr check
	if (!fileName)
	{
		return {};
	}

	std::ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		return {};
	}

	//ще извика функцията, която приема поток
	return parseFromFile(ifs);
}

void printTable(const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		for (int j = 0; j < table.collsCount; j++)
		{
			std::cout << table.rows[i][j] << "           ";
		}

		std::cout << std::endl;
	}
}

void saveRowToFile(std::ostream& ofs, const Row& row, size_t collsCount)
{
	for (int i = 0; i < collsCount; i++)
	{
		ofs << row[i];
		
		//ако НЕ се намираме на последното поле трябва
		//да запазим и разделителя след него
		if (i != collsCount - 1)
		{
			ofs << GlobalConstants::SEP;
		}
	}
}

void saveToFile(std::ostream& ofs, const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		saveRowToFile(ofs, table.rows[i], table.collsCount);

		//ако НЕ се намираме на последния ред рябва
		//да преминем на нов ред, за да разделим редовете 
		if (i != table.rowsCount - 1)
		{
			ofs << std::endl;
		}
	}
}

void saveToFile(const char* fileName, const CsvTable& table)
{
	//nullptr check
	if (!fileName)
	{
		return;
	}

	std::ofstream ofs(fileName);

	//is file found check
	if (!ofs.is_open())
	{
		return;
	}

	saveToFile(ofs, table);
	ofs.close();

}

int getColumnIndex(const CsvTable& csvTable, const char* columName)
{
	//справяне със случая, ако таблицата няма редове
	assert(csvTable.rowsCount >= 1);
	
	//nullptr check
	if (!columName)
	{
		return -1;
	}

	for (int i = 0; i < csvTable.collsCount; i++)
	{
		if (std::strcmp(csvTable.rows[0][i], columName) == 0)
		{
			//намерили сме търсената колона и връщаме нейния индекс
			return i;
		}
	}
	
	return -1;
}

bool modify(CsvTable& csv, const char* columnName, const char* newValues, char sep)
{
	int columnIndex = getColumnIndex(csv, columnName);
	if (columnIndex < 0)
	{
		//неуспешен modify
		return false;
	}

	std::stringstream ss(newValues);
	int rowIndex = 1;
	while (!ss.eof())
	{
		if (rowIndex >= csv.rowsCount)
		{
			break;
		}

		//запазваме новите стойности в съответстващите им клетки
		ss.getline(csv.rows[rowIndex++][columnIndex], GlobalConstants::FIELD_MAX_SIZE, sep);
	}

	//успешен modify
	return true;
}

int main()
{
	CsvTable myFile = parseFromFile("students1.csv");

	printTable(myFile);

	modify(myFile, "Fakulteten nomer", "asd|test|test", '|');

	saveToFile("students_new.csv", myFile);

	return 0;
}