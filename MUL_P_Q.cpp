//Тазеруалет М.А. гр. 5306

//Функция для умножения многочлена на рациональное число

DM_P MUL_P_Q(DM_Q *c, DM_Z a, DM_Z b, unsigned short m)
{
	for (int i = 0; i < m; i++)
		*(c + i) = (*(c + i)) * (a / b);
	return *c;
}
