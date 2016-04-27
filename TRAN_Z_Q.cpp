//Лавров О. А.
//Модуль: TRAN_Z_Q - преобразование целого числа в дробное
//Возвращаемое значение: Рациональное число


DM_Q TRAN_Z_Q(DM_Z z1){
  DM_Q temp = new DM_Q();
  temp.a = z1;
  temp.b = DM_Z(1);
  return temp;
}

