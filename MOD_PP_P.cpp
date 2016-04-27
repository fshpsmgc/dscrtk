//Об авторе:
//Томинг Яан Аргович, ФКТИ Гр.№5306
//VK: vk.com/jaann830
//E-Mail: jtoming@gmail.com

//целочисленное деление
DM_P DM_P::operator/(DM_P pDivider)
{
	DM_P pQuotient,														//частное
		 pBuf,															//буфер
		 pEnd;															//остаток
	pBuf.c = new DM_Q[m];												//выделяем память массиву коэффициентов буфера
	pQuotient.c = new DM_Q[m];											//выделяем память массиву коэффициентов частного
	pEnd.c = c;															//приравниваем остатку частное
	pEnd.m = m;
	while (pEnd.DEG_PP_N() >= pDivider.DEG_PP_N())						//цикл, пока степень остатка выше степени делителя
	{
		pBuf.m = 0;														//приравниваем степени буфера нуль
		pBuf.c[0] = pEnd.c[0].DIV_QQ_Q(pDivider.c[0]);					//находим частное коэффициентов
		pBuf = pBuf.MUL_Pxk_P(pEnd.DEG_PP_N() - pDivider.DEG_PP_N());	//домножаем полученное частное коэффициентов на X в степени разности степеней остатка и делителя
		pQuotient = pQuotient.ADD_PP_P(pBuf);							//прибавляем к частному буфер
		pEnd = pEnd.SUB_PP_P(pBuf.MUL_PP_P(pDivider));					//вычитаем из промежуточного результата произведение буфера и делителя
	}
	delete pBuf.c;
	return pQuotient;													//возврат полученного частного	
}
//не тестил модуль
