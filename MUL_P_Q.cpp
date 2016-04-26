//Ведмедь С.В. гр. 5306

//Функция для умножения многочлена на рациональное число

DM_P MUL_P_Q(DM_P plnm, DM_Q alpha){
	DM_P tempPlnm = new DM_P();
	for(int i; i < plnm.m; i++){
		tempPlnm.c[i] = MUL_QQ_Q(plnm.c[i], alpha);
	}
	return tempPlnm;
}
