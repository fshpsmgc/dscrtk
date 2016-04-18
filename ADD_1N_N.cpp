/*
	Назначение: Добавление 1 к натуральному числу

	Возвращаемое значение: Натуральное число

	Параметры: Натуральное число
*/

DM_N ADD_1N_N(DM_N n1){
	int counter = 1;
	DM_N temp;
	temp = n1;
	if(temp.a[temp.n - 1] != 9){ 	//Если последняя цифра числа не равна 9, то прибавляем к ней единицу
		temp.a[temp.n - 1]++;
	}else{							//Если последняя цифра равна 9, то ищем первую цифру, которая не равна 9, прибавляем к ней 1, а всем предыдущим присваиваем 0 
		while(temp.a[temp.n - counter] == 9 && counter != temp.n){
			temp.a[temp.n - counter] = 0;
			counter++;
		}
		if(counter == temp.n){ 		//Если число состоит из цифр 9, то увеличиваем размер массива на 1, присваиваем цифре в старшем разряде 1, а всем остальным цифрам присваиваем значение 1
			temp.a = (short unsigned int*) realloc(temp.a, sizeof(short unsigned int)*temp.n + 1);
			temp.a[0] == 1;
			for(int i = 1; i < temp.n; i++){
				temp.a[i] = 0;
			}
		}else{
			temp.a[temp.n - counter]++;
		}
		
	}
	return temp;
}