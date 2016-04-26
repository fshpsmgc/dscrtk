/*
ФИО: Гараев Никита Рравнрестамович
e-mail: mqmpgl@gmail.com
Операция: НОК двух натуральных чисел
Принимаемые значения: op1 - класс DM_N, op2 - класс DM_N
Возвращаемое значение: Наименьшее общее кратное result - класс DM_N
Алгоритм: НОК двух чисел вычисляется по следующей формуле
                            a*b
                    LCM = -------- , где a, b - натур. числа, LCM - НОК, GFC - НОД
                          GCF(a,b)
*/
DM_N LCM_NN_N(DM_N op1, DM_N op2) {
    DM_N a, b, result;
    a = op1 * op2;
    b = MOD_NN_N(op1, op2);
    result = DIV_NN_N(a, b);
    return result;
}
