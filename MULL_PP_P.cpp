// ============================= ����� =====================================
//�� ������ 
//����� ������� ���� ��.�5306  
//E-Mail: yanaki.evgeny5306@gmail.com

//�������: ��������� ����������� 
// 
//������������ ��������: 
//�������������� ��������� 
// 
//���������: 
//����������, ������� ����� ����������� 

DM_P MULL_PP_P(DM_P *P1, DM_P *P2)
{
	DM_P S;									//������� ����������, � ������� ����� �������� �������������� ���������
	for (int k = 0;k < P1->m;k++)			//��������� ����������� ������ ���� ������� ���������� �� ������
		for (int j = 0;j < P2->m;j++)
			if P2->(*c)::operator [] (j) != 0 then
				S = ADD_PP_P(S, MUL_Pxk_P(MUL_P_Q(*P1, P2->c::operator[](j)), j);//������� �������� �� ������� �����������,
	return S;								//����� �� "x" ������ �������, ��������� ���������� � ��������������� ����������
}