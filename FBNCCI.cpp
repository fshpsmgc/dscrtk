//Об авторе:
//Томинг Яан Аргович, ФКТИ Гр.№5306
//VK: vk.com/jaann830
//E-Mail: jtoming@gmail.com

//вывод iMax элементов ряда Фибоначчи
void DM_N::FBNCCI(int iMax)												
{
	DM_N nF, a, b;
	a = 1;															
	b = 1;															//инициализация единицами первых 2 элементов ряда
	for (int i = 0; i < iMax; i++)									//цикл с заданным количеством повторений
	{
		nF = a + b;													//суммируем предыдущие 2 элемента ряда
		if (i % 2 == 0)												//через раз кидаем полученный элемент в a и b
			a = nF;
		else
			b = nF;
		nF.print();													//вывод с переносом строки
		puts("");
	}
}
