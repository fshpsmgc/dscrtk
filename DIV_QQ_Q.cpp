// ������� �.�.
// ������: DIV_QQ_Q - ������� ������.
// ������������ ��������: ���. �����
// ���������:  f1 - ������ ����� 
//             f2 - ������ �����

DM_Q DIV_QQ_Q(DM_Q f1, DM_Q f2)
{
	DM_Q res; // �������. �����
	res.a = MUL_ZZ_Z(f1.a, f2.b); // ������� ���������
	res.b = MUL_ZZ_Z(f1.b, f2.a); // ������� �����������
	return res;
}
// �� ������ 