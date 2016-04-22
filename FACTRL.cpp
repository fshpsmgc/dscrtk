//вычисление факториала числа
DM_N DM_N::operator! ()
{
	DM_N nFactorial = 1;
	for (DM_N i = 1; COM_NN_D(i, this) == 1; i + 1)			//умножаем в цикле на каждое число от 1 до входного натурального
		nFactorial = nFactorial*i;
	return nFactorial;
}
