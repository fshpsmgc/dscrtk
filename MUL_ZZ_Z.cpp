Автор: Вялков Дмитрий
Задача модуля: умноженние целых чисел

DM_Z MUL_ZZ_Z(DM_Z n1, DM_Z n2){
	DM_N n1abs;					//модуль первого числа
	DM_N n2abs;					//модуль второго числа
	DM_N natres;				//модуль произведения
	DM_Z res;					//произвеление
	n1abs = ABS_Z_N(n1);
	n2abs = ABS_Z_N(n2);
	natres = MUL_NN_N(n1, n2);
	res = TRANS_N_Z(natres);	
	if(n1.b == n2.b){			//если знаки чисел равны то выводим произвеление
		return res;
	}else{						//если знаки чисел не равны то умножаем произведение на -1
		return MUL_ZM_Z(res)	
	}	
}
