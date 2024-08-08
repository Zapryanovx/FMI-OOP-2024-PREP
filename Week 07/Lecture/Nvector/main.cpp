﻿//#ОБЯСНЕНИЕ НА ЗАДАЧАТА
// 
// Реализирайте клас Nvector, който ще се използва за работа с математически вектор.
//
// Предефинирайте оператори със следната функционалност:

//Събиране на вектори.
//Изваждане на вектори.
//Умножение на вектор със скалар.
//Проверка дали два вектора са успоредни.
//Проверка дали два вектора са перпендикулярни.
//Взимане на дължина на вектор.
//Достъп до произволен елемент на вектор.
//Вход и изход от потоци.

#pragma once
#include <iostream>
#include "NVector.h"

using namespace std;

int main()
{
    NVector v(4);
    cin >> v;

    NVector v2(4);
    cin >> v2;

    NVector result = v + v2;

    cout << (v |= v2) << endl;
    cout << (v || v2) << endl;
    cout << (v % v2) << endl;


}