/*
ФИО: Гараев Никита Рравнрестамович
e-mail: mqmpgl@gmail.com
Операция: НОД двух натуральных чисел
Принимаемые значения: op1 - класс DM_N, op2 - класс DM_N
Возвращаемое значение: Наибольший общий делитель a - класс DM_N
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
    } while (c);
    return ((a.a != NULL) ? a : -1);
}

