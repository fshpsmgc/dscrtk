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