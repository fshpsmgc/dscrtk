/*
ФИО: Гараев Никита Рустамович
e-mail: mqmpgl@gmail.com
Операция: НОД двух натуральных чисел
Принимаемые значения: op1 - объект класса DM_N, op2 - объект класса DM_N
Возвращаемое значение: Наибольший общий делитель a - объект класса DM_N
Алгоритм: алгоритм Евклида
*/
DM_N GCF_NN_N(DM_N op1, DM_N op2) {
    if(op1.a == NULL || op2.a == NULL)
        return -1;
    DM_N a = op1;
    DM_N b = op2;
    DM_N c;
    do{
        c = MOD_NN_N(a, b);
        a = b;
        b = c;
    } while (c.a);
    return ((a.a != NULL) ? a : -1);
}

