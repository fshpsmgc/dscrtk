//Ершов Даниил 
//daniilershov2015@gmail.com
DM_P DM_P::NMR_P_P()
{
	DM_P NOD_P, NOD_M, derivative, M, answer; 
	detriative = DER_P_P(this); //находим производную многочлена
	NOD_P = this.GCF_PP_P(detriative);// находим НОД(1) многочлена и его производной
	M = this / NOD_P; // находим отношения многочлена к НОД(1) 
	NOD_M = M.GCF_PP_P(NOD_P); //находим НОД(2) отношения М и НОД(1)
	answer = M / NOD_M; //получаем ответ путем деления М на НОД(2)
	retu
