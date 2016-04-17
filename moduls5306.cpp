#include "stdafx.h"
#include "DataTypes.h"
#include <iostream>
#include "moduls5306.h"

// ============================= ������� ====================================
//����������:
//������� ��� ��������� ���� ����������� �����
//
//������������ ��������:
//2 - ���� ������ ����� ������
//1 - ���� ������ ����� ������
//0 - ���� ����� �����
//
//���������:
//����� �1
//����� �2

int COM_NN_D(DM_N n1, DM_N n2)
{
	if (n1.n > n2.n)				//���������� ����� �����
		return 2;
	else
		if (n1.n < n2.n)
			return 1;

	for (int i = n1.n; i >= 0; i--)	//���� ����� ����� �����, �� ��������� � ������������ ���������
		if (n1.a[i] > n2.a[i])
			return 2;
		else
			if (n1.a[i] < n2.a[i])
				return 1;

	return 0;
}

//======
//����������:
//������� ��� ��������� ������������ ����� �� 10 � ������� k
//
//������������ ��������:
//�����������
//
//���������:
//���������� �����
//������� ��������� 10

void MUL_Nk_N(DM_N &obj, unsigned short k)
{
	DM_N temp;		//��������� ����������, �������� ������ ������
	temp.a = obj.a;
	temp.n = obj.n;

	short uselessZeroes = 0;
	for (short i = temp.n - 1; i >= 0 && obj.a[i] == 0; i--)
		++uselessZeroes;

	if (k > uselessZeroes)
		obj.n += k - uselessZeroes;
	obj.a = new unsigned short[obj.n];

	for (short i = obj.n - 1; i >= 0; i--)
		if (i < k)
			obj.a[i] = 0;
		else
			obj.a[i] = temp.a[i - k];
}

//======
//����������:
//����������� ����������
//
//������������ ��������:
//���������
//
//���������:
//���������, ����������� �������� ������

DM_P DER_P_P(const DM_P &obj)
{
	DM_P *result = new DM_P;
	result->c = new DM_Q[obj.m];
	for (int i = 1; i <= obj.m; i++)
		result->c[i - 1] = obj.c[i] * i;
	result->m = obj.m - 1;
	return *result;
}


// ============================= ����� ====================================
//�� ������ 
//����� ������ �������������� ���� ��.�5306  
//E-Mail: daniilershov2015@gmail.com

//������� �������������� ������������ ����� � ����� 
DM_Z TRANS_N_Z(DM_N nat) 
{
	DM_Z cel;         //����� ����� ������� ����� ���������� �������
	cel.n = nat.n;    //���������� ������� ������
	cel.a = (short unsigned int*)malloc(sizeof(short unsigned int)*cel.n); //�������� ������ ��� ������ ����
	for (int i = 0; i < cel.n; i++)   //����������� �������� �������� ������������ ����� ������
		cel.a[i] = nat.a[i];
	cel.b = 0; // ������������� ���� �����
	return cel; // ���������� ����� �����
}

//������� ����������� ��������������� �����
short unsigned int POZ_Z_D(DM_Z cel)  
{
	short unsigned int sign;	//������ �������� �������� 1, ���� ����� �������������,
								//2 ���� ����� ������������� � 0 ���� ����� ����� 0
	bool zero = true;
	for (int i = 0; i < cel.n && zero; i++)
		zero = (cel.a[i] == 0);		//���� ��� ����� � ������� ����� 0, ������������� ����� ����� 0

	if (zero)
		sign = 0;
	else
		if (cel.b == 0)
			sign = 1;
		else
			sign = 2;

	return sign;
}

//������� ��������� ������ ����� �� -1
void MUL_Zm_Z(DM_Z *cel) 
{
	if(cel->n != 1 || cel->a[0] != 0)	//���� ����� �� ����
		cel->b = !(cel->b);		//����������� ���� �����
}

// ============================= ������ ====================================



// ============================= ������ ====================================