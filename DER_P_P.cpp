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