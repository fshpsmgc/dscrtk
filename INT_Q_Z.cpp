/*
  Проверка на целое, если рациональное число является целым, то «да», иначе «нет»
*/

bool INT_Q_Z(DM_Q n1){
  if(n1.b.n == 1 && n1.b.a[0] == 1){
    return true;
  }else{
    return false;
  }
}
