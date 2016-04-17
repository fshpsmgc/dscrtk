/*
	Назначение: функция проверки числа на ноль

	Возвращаемое значение: Если число равно 0, то false, иначе true

	Параметры: Натуральное число	
*/

bool NZER_N_B(DM_N n1){
	bool flag = false;
	for(int i = 0; i < n1.n && flag == false; i++){
		if(n1.a[i] == 0){
			flag = true;
		}
	}
}