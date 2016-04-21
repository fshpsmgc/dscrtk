//Об авторе:
//Диденеко Олег Александрович, ФКТИ Гр.№5306
//VK: http://new.vk.com/diaglyonok
//E-Mail: diaglyonok@yandex.ru

//Назначение: Модуль делит большее целое число на меньшее целое число.
//Тип возвращаемого значения - целое
//Функция ссылается на следующие модули: TRANS_Z_N, TRANS_N_Z, NZER_N_B, COM_NN_D, SUB_NN_N, ADD_1N_N, POZ_Z_D, MUL_Z-_Z;

DM_Z DIV_ZZ_Z (DM_Z X1, DM_Z X2)
{
    DM_N t;  //Объявляем переменную счётчик
    DM_N natX1 = TRANS_Z_N (X1); //Объявляем натуральные аналоги целым числам
    DM_N natX2 = TRANS_Z_N (X2);
    if (!NZER_N_B(natX2))    //Если делитель равен нулю. выдаем ошибку
        printf("Делитель равен нулю.");
    else if (COM_NN_D(natX1, natX2)==2)  //Если Первое число больше второго:
    {
        do
        {
            natX1=SUB_NN_N(natX1, natX2); //Вычитаем из большего числа меньшее
            t=ADD_1N_N(t);      //Наращиваем t
        }
        while (COM_NN_D(natX1, natX2)==2); //Цикл пока делимое больше делителя
        t = TRANS_N_Z(t);  //Переводим результат в целое
        if (POZ_Z_D(X1)==1 && POZ_Z_D(X2)==2 || POZ_Z_D(X1)==2 && POZ_Z_D(X2)==1)
           t= MUL_Z-_Z(t); //Если исходные числа имеют разные знаки,
                           //Поменять знак у результата
        return t;
    }

    else if (COM_NN_D(natX1, natX2)==1) //Если второе число больше первого:
    {                                   //Выполняем аналогичные действия.
        do
        {
            natX1=SUB_NN_N(natX1,natX1);
            t=ADD_1N_N(t);
        }
        while (COM_NN_D(natX1, natX1)==2);
        t = TRANS_N_Z(t);
        if (POZ_Z_D(X1)==1 && POZ_Z_D(X2)==2 || POZ_Z_D(X1)==2 && POZ_Z_D(X2)==1)
           t= MUL_Z-_Z(t);
        return t;
    }
    else if (COM_N_D(natX1, natX2)==0)  // Если числа равны:
    {
        t = TRANS_N_Z(t);  // Переводим t в целое
        t.a[0]=1;  //Присваиваем результату значение 1
        t.n=1;
        if ((POZ_Z_D(X2)==2 && POZ_Z_D(X1)==1) || (POZ_Z_D(X2)==1 && POZ_Z_D(X1)==2))
        t.b=!t.b; //Если исходные числа имели разные знаки, меняем знак результата.
    }
    return t;
}

//Не тестил.
