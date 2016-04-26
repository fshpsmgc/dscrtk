/*
ФИО: Гараев Никита Рравнрестамович
e-mail: mqmpgl@gmail.com
Операция: НОД двух натуральных
Принимаемые значения: op1 - структура DM_N, op2  структура DM_N
Возвращаемое значение: Наибольший общий делитель
*/
DM_N DM_N::GCF_NN_N(DM_N op1, DM_N op2) {
    DM_N a = op1;
    DM_N b = op2;
    DM_N c;
    do{
        c->a = MOD_NN_N(a->a, b->a);
        a->a = b->a;
        b->a = c->a;
    } while (c->a);
    return c->a;
}
