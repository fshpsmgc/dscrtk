// ������ �. �.
// ������: ADD_QQ_Q - �������� ������.
// ������������ ��������: ���. �����
// ���������:  q1 - ������ ����� 
//             q2 - ������ �����

DM_Q ADD_QQ_Q(DM_Q q1, DM_Q q2)
{
	DM_Q res; // �������������� �����
	res.a = ADD_ZZ_Z(MUL_ZZ_Z(q2.b, q1.a), MUL_ZZ_Z(q1.b, q2.a)); // ����������� ���������
	res.b = MUL_ZZ_Z(q1.b, q2.b);                                 // ����������� ����� ����������� 
	return res;   
} 