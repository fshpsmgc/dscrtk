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