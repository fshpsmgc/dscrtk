DM_Z MUL_QQ_Q(DM_Z n1, DM_Z n2){
	DM_N n1abs;
	DM_N n2abs;
	DM_N natres;
	DM_Z res;
	n1abs = ABS_Z_N(n1);
	n2abs = ABS_Z_N(n2);
	natres = MUL_NN_N(n1, n2);
	res = TRANS_N_Z(natres);
	if(n1.b == n2.b){
		return res;
	}else{
		return MUL_ZM_Z(res)
	}	
}