//������ �������
//��� ����������� �����
DM_N GCF_NN_N (n1, n2) {
	
	DM_N t;
	
	switch (COM_NN_D(n1, n2)) {						//������ ��������� ����������� �����

		case 0:							
			return 0;								//����� �����, ���������� 0

		case 1:										//n1 < n2, ������ ����� �������
			t = n1;
			n1 = n2;
			n2 = t;

		case 2:										//���������� �������� �������
			for (;;) {
				if (NZER_N_B(MOD_NN_N(n1, n2))) {	//��������� ������� �� ������� n1 �� n2 �� ��������� ����
					n1 = n2;						//���� ������� �� ����� ���� �� ��������� � ����������
					n2 = MOD_NN_N(n1, n2);			//���� ���������
				} 
				else return n2;						//���� ������� ����� ���� ���������� n2
			}
			
	}
}
//�� ������