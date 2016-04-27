/*
ФИО: Гараев Никита Рустамович
e-mail: mqmpgl@gmail.com
Операция: НОК двух натуральных чисел
Принимаемые значения: op1 - объект класса DM_N, op2 - объект класса DM_N
Возвращаемое значение: Наименьшее общее кратное result - объект класса DM_N
Алгоритм: НОК двух чисел вычисляется по следующей формуле
                            a*b
                    НОК = -------- , где a, b - натур. числа
                          НОД(a,b)
*/
DM_N LCM_NN_N(DM_N op1, DM_N op2) {
    if(op1.a == NULL || op2.a == NULL)
        return -1;
    DM_N a, b, result;
    a = op1* op2;
    b = MOD_NN_N(op1, op2);
    result = DIV_NN_N(a, b);
    return ((result.a != NULL) ? result : -1);
}
