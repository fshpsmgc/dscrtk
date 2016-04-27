/*
ФИО: Гараев Никита Рустамович
e-mail: mqmpgl@gmail.com
Операция: Остаток от деления большего натурального числа на меньшее или равное
Принимаемые значения: op1 - объект класса DM_N, op2 объект класса DM_N
Возвращаемое значение: Остаток от деления - объект класса DM_N или -1 в случае ошибки
Алгоритм: Ищем N: A = N*B + r, где B <= A, r < B, А - делимое, B - делитель, r - остаток
Т.к. N: A = N*B + r, то r = A - N*B
*/
DM_N MOD_NN_N(DM_N op1, DM_N op2) {
    if(op1.a == NULL || op2.a == NULL)
        return -1;
    int N = 0;
    do {
    N++;
    } while(COM_NN_D(op1, op2* N) == 2); //while A > N*B
    N--; // N: A = N*B + r 
    DM_N temp; // r
    temp = SUB_NN_N(op1, op2* N); //r = A - N*B
    return ((temp.a != NULL) ? temp : -1);
}

