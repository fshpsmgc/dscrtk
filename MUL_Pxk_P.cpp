//Тазеруалет М.А. гр.5306
//Умножение многочлена на x^k 

//Функция для умножения многочлена на x^k
DM_P MUL_Pxk_P(DM_P obj, unsigned short k)
{
	DM_P *result;		//Создаем новый
	result = new DM_P;

	result->m = obj.m + k;				//Его степень увеличится
	result->c = new DM_Q[result->m + 2];

	for (short i = 0; i < k; ++i)		//Забиваем нулями новые члены
		result->c[i] = { 0, 1 };

	for (short i = 0; i < obj.m + 1; ++i)	//Переносим старые
		result->c[i + k] = obj.c[i];

	return *result;
}