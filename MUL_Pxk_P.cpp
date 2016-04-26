//Тазеруалет М.А. гр. 5306
//Функция для умножения многочлена на x^k 

DM_P MUL_Pxk_P(DM_Q *c, unsigned short m, unsigned short k, unsigned short x)
{
	for (int i = 0; i < m; i++)
		*(c + i) = (*(c + i)) * x^k;
	return *c;
}
