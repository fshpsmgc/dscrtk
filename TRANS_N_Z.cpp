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
