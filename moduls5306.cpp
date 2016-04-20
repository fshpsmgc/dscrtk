#include "stdafx.h"
#include "DataTypes.h"
#include <iostream>
#include "moduls5306.h"

// ============================= Сидоров ====================================
//Назначение:
//Функция для сравнения двух натуральных чисел
//
//Возвращаемое значение:
//2 - если первое число больше
//1 - если второе число больше
//0 - если числа равны
//
//Параметры:
//Число №1
//Число №2

int COM_NN_D(DM_N n1, DM_N n2)
{
	if (n1.n > n2.n)				//Сравниваем длины чисел
		return 2;
	else
		if (n1.n < n2.n)
			return 1;

	for (int i = n1.n; i >= 0; i--)	//Если длины чисел равны, то переходим к поразрядному сравнению
		if (n1.a[i] > n2.a[i])
			return 2;
		else
			if (n1.a[i] < n2.a[i])
				return 1;

	return 0;
}

//======
//Назначение:
//Функция для умножения натурального числа на 10 в степени k
//
//Возвращаемое значение:
//Отсутствует
//
//Параметры:
//Изменяемое число
//Степень множителя 10

void MUL_Nk_N(DM_N &obj, unsigned short k)
{
	DM_N temp;		//Временная переменная, хранящая старые данные
	temp.a = obj.a;
	temp.n = obj.n;

	short uselessZeroes = 0;
	for (short i = temp.n - 1; i >= 0 && obj.a[i] == 0; i--)
		++uselessZeroes;

	if (k > uselessZeroes)
		obj.n += k - uselessZeroes;
	obj.a = new unsigned short[obj.n];

	for (short i = obj.n - 1; i >= 0; i--)
		if (i < k)
			obj.a[i] = 0;
		else
			obj.a[i] = temp.a[i - k];
}

//======
//Назначение:
//Производная многочлена
//
//Возвращаемое значение:
//Многочлен
//
//Параметры:
//Многочлен, производная которого ищется

DM_P DER_P_P(const DM_P &obj)
{
	DM_P *result = new DM_P;
	result->c = new DM_Q[obj.m];
	for (int i = 1; i <= obj.m; i++)
		result->c[i - 1] = obj.c[i] * i;
	result->m = obj.m - 1;
	return *result;
}


// ============================= Ершов ====================================
//Об авторе 
//Ершов Даниил Константинович ФКТИ Гр.№5306  
//E-Mail: daniilershov2015@gmail.com

//Функция преобразования натурального числа в целое 
DM_Z TRANS_N_Z(DM_N nat) 
{
	DM_Z cel;         //целое число которое будет возвращать функция
	cel.n = nat.n;    //запоминаем старший разряд
	cel.a = (short unsigned int*)malloc(sizeof(short unsigned int)*cel.n); //выделяем память под массив цифр
	for (int i = 0; i < cel.n; i++)   //присваиваем значения разрядов натурального числа целому
		cel.a[i] = nat.a[i];
	cel.b = 0; // устанавливаем знак числа
	return cel; // вовзращаем целое число
}

//Функция определения положительности числа
short unsigned int POZ_Z_D(DM_Z cel)  
{
	short unsigned int sign;	//Функия хранящая значение 1, если число положительное,
								//2 если число отрицательное и 0 если число равно 0
	bool zero = true;
	for (int i = 0; i < cel.n && zero; i++)
		zero = (cel.a[i] == 0);		//Если все числа в массиве равны 0, следовательно число равно 0

	if (zero)
		sign = 0;
	else
		if (cel.b == 0)
			sign = 1;
		else
			sign = 2;

	return sign;
}

//Функция умножения целого числа на -1
void MUL_Zm_Z(DM_Z *cel) 
{
	if(cel->n != 1 || cel->a[0] != 0)	//Если число не ноль
		cel->b = !(cel->b);		//Инвертируем поле знака
}

// ============================= Томинг ====================================



// ============================= Гуляев ====================================

//Функция для вычитания целых чисел
//Возвращаемое значение: целое число
//Параметры: minuend - уменьшаемое целое число, subtrahend - вычитаемое целое число.

DM_Z SUB_ZZ_Z(DM_Z minuend, DM_Z subtrahend)
{
    DM_Z result;

    if (COM_NN_D(ABS_Z_N(minuend), ABS_NN_D(subtrahend)) == 0)                 //Проверили числа на равенство
    {
        if (POZ_Z_D(minuend) == POZ_Z_D(subtrahend))                           //Числа равны по модулю
        {                                                                      //Знаки одинаковы
            result.b = 0;                                                      //Знак разности "+"
            result.n = 0;                                                      //Номер старшей позиции разности
            result.a = new unsigned short [1] ;                                 //Выделение памяти
            result.a[0] = 0;                                                   //Разность равна нулю
        }
        else
        {                                                                      //Знаки разные
            result.a = ADD_NN_N(ABS_Z_N(minuend), ABS_Z_N(subtrahend));        //Сложение модулей натуральных чисел
            result.b = minuend.b;                                              //Знак разности равен знаку уменьшанмого

        }
    }
    else
    {                                                                         //Числа не равны
        if (POZ_Z_D(minuend) == POZ_Z_D(subtrahend))                          //Знаки совпадают
        {
            result.a = SUB_NN_N(ABS_Z_N(minuend), ABS_Z_N(subtrahend));       //Вычитание из первого большего натурального числа второго меньшего натурального
            if (POZ_Z_D(minuend) == 1)
                result.b = 0;                                                  //Знак разности "+"
            else
                result.b = 1;                                                  //Знак разности "-"
        }
    }
    return result;                                                             //Возвращаем результат
}


//Сложение многочленов
//Автор: Гуляев Максим Андреевич группа № 5306
//Возвращаемое значение: многочлен
//Параметры: first_p - первый многочлен, second_p - второй многочлен

DM_P ADD_P_PP(DM_P first_p, DM_P second_p)
{
    DM_P result;
    result.c = NULL;
    int k = 0;

    if (first_p.m >= second_p.m)                                             //Если степень первого многочлена больше второго
    {
        result.m = first_p.m;                                                //Степень многочлена суммы будет равна степени первого многочлена
        result.c = new DM_Q[first_p.m];                                      //Выделение памяти

        for (int i = 0; i < second_p.m; i++)
        {
            result.c[i] = ADD_QQ_Q(first_p.c[i], second_p.c[i]);            //Складываем коэфиценты двух многочленов
            k = i;
        }
        for (int i = k; i < first_p.m; i++)
        {
            result.c[i] = first_p.c[i];                                      //Проставляем коэфиценты при степенях старше степени меншего многочлена
        }
    }
    else                                                                    //Если степень второго ногочлена больше степени первого
    {
        result.m = second_p.m;                                              //Степень многочлена суммы будет равна степени второго многочлена
        result.c = new DM_Q[second_p.m];

        for (int i = 0; i < first_p.m; i++)
        {
            result.c[i] = ADD_QQ_Q(first_p.c[i], second_p.c[i]);           //Складываем коэфиценты двух многочленов
            k = i;
        }
        for (int i = k; i < second_p.m; i++)                               //Проставляем коэфиценты при степенях старше степени меньшего многочлена
        {
            result.c[i] = second_p.c[i];
        }
    }
    return result;                                                         //Возвращаем результат
}


//Умножение дробей
//Автор: Гуляев Максим Андреевич группа № 5306
//Возвращаемое значение: рациональное число
//Параметры: factor_a- первая дробь, factor_b - вторая дробь;

DM_Q MUL_QQ_Q(DM_Q factor_a, DM_Q factor_b)
{
    DM_Q result;

    result.a = MUL_ZZ_Z(factor_a.a, factor_b.a);                        //Перемножаем числители двух дробей
    result.b = MUL_ZZ_Z(factor_a.b, factor_b.b);                        //Перемножаем знаменатели двух дробей

    return result;                                                      //Возвращаем результат
}

// ============================= Янаки =====================================
//Об авторе 
//Янаки Евгений ФКТИ Гр.№5306  
//E-Mail: yanaki.evgeny5306@gmail.com

//Функция: Oпределениe степени многочлена
//
//Возвращаемое значение:
//Натуральное число соответстующее степени многочлена
//(0 - если все коэффициенты, кроме м.б свободного члена, равны 0)
//
//Параметры:
//Массив коэффициентов, количество коэффициентов

unsigned short DEG_P_N(DM_P *P)
{
	unsigned short d = P->m - 1;				//Задаем переменную, в которой будет хранится степень многочлена
	for (int i = 0; i <P->m - 1; i++)			//Проверяем, не являются ли первые коэффициенты 0, если так, то уменьшаем степень
		if P->c::operator [] (i) != 0 then
			return d;
		else
			d--;
	return d;
}

//Функция: Умножение многочленов 
// 
//Возвращаемое значение: 
//Результирующий многочлен 
// 
//Параметры: 
//Многочлены, которые нужно перемножить 

DM_P MULL_PP_P(DM_P *P1, DM_P *P2)
{
	DM_P S;									//Создаем переменную, в которой будет хранится результирующий многочлен
	for (int k = 0;k < P1->m;k++)			//Поочереди перемножаем каждый член первого многочлена на второй
		for (int j = 0;j < P2->m;j++)
			if P2->(*c)::operator [] (j) != 0 then
				S=ADD_PP_P(S,MUL_Pxk_P(MUL_P_Q(*P1,P2->c::operator[](j)),j);//Сначала умножаем на текущий коэффициент,
	return S;								//затем на "x" нужной степени, результат прибавляем к результирующему многочлену
}

//Функция: Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей 
// 
//Возвращаемое значение: 
//Коэфиент при многочлене 
// 
//Параметры: 
//Массив коэффициентов, количество коэффициентов 

DM_Q FAC_P_PQ(DM_P *P)
{
	DM_N copy;                                                //Заводим переменную, хранящую числители/знаменатели многочлена в натуральном виде
	DM_Q K = { 1,1 };										  //Заводим переменную, хранящую коэффициент
	copy.n = P->m;											  //Устанавливаем кол-во числителей/знаменателей равным кол-ву коэф. многочлена
	for (int i = 0;i < P->m;i++)							  //Заполняем переменную знаменателями коэф. многочлена в натуральном виде
		if (*P)::operator[](i).b<0 then
			copy::operator[](i) = ABS_Z_N((*P)::operator[](i).b);
		else
			copy::operator[](i) = TRANS_Z_N((*P)::operator[](i).b);
	K.b = K.b*TRANS_N_Z(LCM_NN_N(copy));					  //Находим НОК
	for (int i = 0;i < P->m;i++)							  //Умножаем числитель на НОК, чтобы все было по правилам
		(*P)::operator[](i).a = (*P)::operator[](i).a*K.b;
	for (int i = 0;i < P->m;i++)							  //Заполняем переменную числителями коэф.многочлена в натуральном виде
		if (*P)::operator[](i).a then
			copy::operator[](i) = ABS_Z_N((*P)::operator[](i).a);
		else
			copy::operator[](i) = TRANS_Z_N((*P)::operator[](i).a);
	K.a = K.a*TRANS_N_Z(GCF_NN_N(copy));					  //Находим НОД
	for (int i = 0;i < P->m;i++)							  //Делим числитель на НОД, чтобы все было по правилам
		(*P)::operator[](i).a = (*P)::operator[](i).a / K.a;
	return K;
}
