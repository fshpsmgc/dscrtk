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
