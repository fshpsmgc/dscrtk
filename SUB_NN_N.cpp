/*
	Назначение: Вычитание из первого большего натурального числа второго меньшего или равного

	Возвращаемое значение: Натуральное число

	Параметры: Два натуральных числа
*/

DM_N SUB_NN_N(DM_N n1, DM_N n2){
	DM_N temp;

	if(COM_NN_D(n1, n2) == 2){ //Если n1 > n2 число больше
		for(int  i = n1.n; i > n2.n; i--){
			if(n1.a[i] - n2.a[i] >= 0){ 				//Если разность чисел больше нуля,
				temp.a[i] = n1.a[i] - n2.a[i];		//Тогда просто вычитаем большее из меньшего
			}else{															//Иначе
				n1.a[i - 1]--;										//"Занимаем" 10 из следующего разряда, а затем вычитаем
				n1.a[i] += 10;
				temp.a[i] = n1.a[i] - n2.a[i];
			}

		}
	} else if (COM_NN_D(n1, n2) == 1){ // Если n2 > n1 число больше
		for(int  i = n2.n; i > n1.n; i--){
			if(n2.a[i] - n1.a[i] >= 0){				//Если разность чисел больше нуля,
				temp.a[i] = n2.a[i] - n1.a[i];  //Тогда просто вычитаем большее из меньшего
			}else{														//Иначе
				n2.a[i - 1]--;									//"Занимаем" 10 из следующего разряда, а затем вычитаем
				n2.a[i] += 10;
				temp.a[i] = n2.a[i] - n1.a[i];
			}

		}

		//Удаление лишних нулей
		int k = 0;
		int newLength //Размер массива без лишних нулей
		int pos; //Номер первого ненулевого элемента
		while(temp.a[k] == 0){ //Вычисление длины нового числа
			k++;
		}
		if(k != 0){						//Если есть лишние нули
			newLength = temp.n - k;
			for(int j = 0; j < newLength; j++){ //Сдвигаем число в начало массива
				temp.a[j] = temp.a[j + pos];
			}
			temp.a = (short unsigned int*) realloc(temp.a, sizeof(short unsigned int)*newLength); //Изменяем размер массива, чтобы он был равен новой длине числа
			temp.n = newLength;
		}

	}else{ //Если n1 = n2
		temp.a = (short unsigned int*) realloc(temp.a, sizeof(short unsigned int));
		temp.n = 1;
		temp.a[0] = 0;
	}

	return temp;
}
