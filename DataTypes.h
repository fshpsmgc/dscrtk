#pragma once
#include "stdafx.h"


// ==================================== НАТУРАЛЬНОЕ ЧИСЛО  ==================================== 

class DM_N
{
public:
	unsigned short *a;	//Массив цифр
	unsigned short n;	//Номер старшей позиции (Количество элементов в массиве)

public:
	DM_N();											//Безаргументный конструктор
	DM_N(unsigned i);								//Конструктор задающий число
	DM_N(const DM_N &obj);							//Конструктор копии
	~DM_N();										//Деструктор
	void print();									//Вывод числа на экран
	unsigned short operator [] (unsigned short i);	//Оператор взятия n-ой цифры
	DM_N operator + (const DM_N &add) const;		//Сложение
	void operator= (const DM_N &equal);				//Присваивание с созданием нового массива
	DM_N operator* (const unsigned int &mul) const;
	DM_N operator* (const DM_N &mul) const;
};

// ==================================== ЦЕЛОЕ ЧИСЛО  ==================================== 

class DM_Z
{
public:
	unsigned short b;	//Знак числа (1 - минус, 0 - плюс)
	unsigned short *a;	//Массив цифр
	unsigned short n;	//Номер старшей позиции (Количество элементов в массиве)

public:
	DM_Z();												//Безаргументный конструктор
	DM_Z(int i);										//Конструктор задающий число
	DM_Z(const DM_Z &obj);								//Конструктор копии
	~DM_Z();											//Деструктор
	void print();										//Вывод числа на экран
	unsigned short operator [] (unsigned short i);		//Оператор взятия n-ой цифры
	void operator= (const DM_Z &equal);					//Приравнивание с созданием отдельного массива в свободной памяти
	DM_Z operator* (const int &mul) const;				//Умножение целого числа на целое число (int)
};

// ==================================== РАЦИОНАЛЬНОЕ ЧИСЛО  ==================================== 

class DM_Q
{
public:
	DM_Z a;			//Числитель
	DM_Z b;			//Знаменталь

public:
	DM_Q();												//Безаргументный конструктор
	DM_Q(DM_Z a, DM_Z b);								//Конструктор задающий число
	~DM_Q();											//Деструктор
	void print();										//Вывод числа на экран
	DM_Q operator* (const int &mul) const;
};

// ==================================== ПОЛИНОМ  ==================================== 

class DM_P
{
public:
	DM_Q *c;			//Массив коэффициентов
	unsigned short m;	//Количество коэффициентов

public:
	DM_P();										//Безаргументный конструктор
	DM_P(DM_Q *a, unsigned short size);			//Конструктор задающий коэффициенты
	~DM_P();									//Деструктор
	DM_Q operator [] (unsigned short i);		//Оператор взятия n-ой цифры
	void print();								//Вывод числа на экран
};


