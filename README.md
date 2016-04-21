# Дискреточка

[![Build status](https://img.shields.io/badge/build-failing-red.svg)
![Code quality](https://img.shields.io/badge/code_quality-shit-red.svg)
![Downloads](https://img.shields.io/badge/downloads-0-green.svg)
![Оценка](https://img.shields.io/badge/%D0%BE%D1%86%D0%B5%D0%BD%D0%BA%D0%B0-N/A-lightgrey.svg)](http://shields.io/)

###Список модулей###
Готовые модули выделены *курсивом*, а готовые и загруженные выделены **жирным**.
  ADD_QQ_Q
  ADD_ZZ_Z
  DIV_NN_Dk
  DIV_QQ_Q
  DIV_ZZ_Z
  GCF_NN_N
  INT_Q_Z
  LCM_NN_N
  LED_P_Z
  MOD_NN_N
  MOD_ZZ_Z
  MUL_P_Q
  MUL_Pxk_P
  RED_Q_Q
  SUB_NDN_N
  SUB_PP_P
  SUB_QQ_Q
  TRAN_Q_Z
  TRAN_Z_Q
  **MUL_PP_P**
  **FAC_P_PQ**
  **DEG_P_N**
  **ABS_Z_N**(это надо перезалить и/или переписать, потому что там говно)
  **ADD_1N_N**
  *ADD_NN_N*
  **COM_NN_D**
  **DER_P_P**
  **DIV_NN_N**
  *DIV_PP_P*
  *GCF_PP_P*
  *MOV_PP_P*
  *MUL_ND_N*
  **MUL_Nk_N**
  *MUL_NN_N*
  **MUL_Z_Z**(тут у кого-то опечатка в названии. Такого модуля нет, но есть MUL_Zm_Z)
  *MUL_ZZ_Z*
  *NMR_P_P*
  **NZER_N_B**
  **POZ_Z_D**
  **SUB_NN_N**
  **TRANS_N_Z**
  *TRANS_Z_N*


###Распределение модулей:###

  **Ведмедь:**

    - Проверка на ноль: если число не равно нулю, то «да» иначе «нет» (NZER_N_B)
    - Добавление 1 к натуральному числу (ADD_1N_N)
    - Вычитание из первого большего натурального числа второго меньшего или равного (SUB_NN_N)

  **Вялков:**

    - Умножение натурального числа на цифру (MUL_ND_N)
    - Умножение натуральных чисел (MUL_NN_N)
    - Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом (SUB_NDN_N)

  **Гараев:**

    - Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля) (MOD_NN_N)
    - НОД натуральных чисел (GCF_NN_N)
    - НОК натуральных чисел (LCM_NN_N)

  **Диденко:**

    - Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля) (DIV_NN_Dk)
    - Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля) (DIV_NN_N)
    - Абсолютная величина числа, результат - натуральное (ABS_Z_N)

  **Ершов:**

    - Определение положительности числа (2 - положительное, 0 — равное нулю, 2 - отрицательное) (POZ_Z_D)
    - Умножение целого на (-1) (MUL_Z_Z)
    - Преобразование натурального в целое (TRANS_N_Z)
    - Преобразование многочлена — кратные корни в простые (NMR_P_P)

  **Жубр:**

    - Сложение целых чисел (ADD_ZZ_Z)
    - Умножение целых чисел (MUL_ZZ_Z)
    - Частное от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля) (DIV_ZZ_Z)

  **Колев:**

    - Остаток от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля) (MOD_ZZ_Z)
    - Сокращение дроби (REQ_Q_Q)
    - Проверка на целое, если рациональное число является целым, то «да», иначе «нет» (INT_Q_Z)

  **Лавров:**

    - Преобразование целого в дробное (TRAN_Z_Q)
    - Преобразование дробного в целое (если знаменатель равен 1) (TRAN_Q_Z)
    - Сложение дробей (ADD_QQ_Q)

  **Мишанов:**

    - Вычитание дробей (SUB_QQ_Q)
    - Деление дробей (делитель отличен от нуля) (DIV_QQ_Q)
    - Вычитание многочленов (SUB_PP_P)

  **Сидоров:**

    - Сравнение натуральных чисел: 2 - если первое больше либо равно второму, 0, если равно, 1иначе. (COM_NN_D)
    - Сложение натуральных чисел (ADD_NN_N)
    - Умножение натурального числа на 10^k (MUL_Nk_N)
    - Производная многочлена (DER_P_P)

  **Тазеруалет:**

    - Умножение многочлена на рациональное число (MUL_P_Q)
    - Умножение многочлена на x^k (MUL_Pxk_P)
    - Старший коэффициент многочлена (LED_P_Z)

  **Янаки:**

    - Степень многочлена (DEG_P_N)
    - Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей (FAC_P_PQ)
    - Умножение многочленов (MUL_PP_P)

  **Томминг:**

    - Преобразование целого неотрицательного в натуральное(TRANS_Z_N)
    - Частное от деления многочлена на многочлен при делении с остатком (DIV_PP_P)
    - Остаток от деления многочлена на многочлен при делении с остатком (MOV_PP_P)
    - НОД многочленов (GCF_PP_P)
