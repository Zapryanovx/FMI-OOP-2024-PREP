//#ОБЯСНЕНИЕ НА ЗАДАЧАТА
// 
// Пример за клас студент с име (с произволна дължина) и масив от оценки(с произволна дължина).

#pragma once
#include <iostream>
#include "GraduatedStudent.h"

int main()
{
	int grades[] = { 3,3,4,4,5,5 };
	GraduatedStudent gr("Test Student", grades, sizeof(grades) / sizeof(int), "Winning!");

	std::cout << gr.getGrades()[3] << std::endl;

	int gradesTwo[] = { 3,3,4,7,5,5 };
	gr.setGrades(gradesTwo, 6);
	std::cout<< gr.getGrades()[3] << std::endl;

	gr.setQuote("Win!");
	std::cout << gr.getQuote() << std::endl;

	return 0;
}