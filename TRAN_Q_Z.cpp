//Лавров О. А.
//Модуль: TRAN_Q_Z - преобразование целого числа в дробное
//Возвращаемое значение: Целое число


DM_Z TRAN_Z_Q(DM_Q q1){
	return q1.a;
}
//Проверочку надо сделать на то, что q.b = 1?

/*DM_Z TRAN_Z_Q(DM_Q q1)
{
  DM_Z res;
  if(q1.b == 1)
    res.*a = q1.a;
  else
    printf("Число не может быть представлено в виде целого");
  return res;
}
/*
