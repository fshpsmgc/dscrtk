#pragma once
#include "stdafx.h"


// ==================================== ����������� �����  ==================================== 

class DM_N
{
public:
	unsigned short *a;	//������ ����
	unsigned short n;	//����� ������� ������� (���������� ��������� � �������)

public:
	DM_N();											//�������������� �����������
	DM_N(unsigned i);								//����������� �������� �����
	DM_N(const DM_N &obj);							//����������� �����
	~DM_N();										//����������
	void print();									//����� ����� �� �����
	unsigned short operator [] (unsigned short i);	//�������� ������ n-�� �����
	DM_N operator + (const DM_N &add) const;		//��������
	void operator= (const DM_N &equal);				//������������ � ��������� ������ �������
	DM_N operator* (const unsigned int &mul) const;
	DM_N operator* (const DM_N &mul) const;
};

// ==================================== ����� �����  ==================================== 

class DM_Z
{
public:
	unsigned short b;	//���� ����� (1 - �����, 0 - ����)
	unsigned short *a;	//������ ����
	unsigned short n;	//����� ������� ������� (���������� ��������� � �������)

public:
	DM_Z();												//�������������� �����������
	DM_Z(int i);										//����������� �������� �����
	DM_Z(const DM_Z &obj);								//����������� �����
	~DM_Z();											//����������
	void print();										//����� ����� �� �����
	unsigned short operator [] (unsigned short i);		//�������� ������ n-�� �����
	void operator= (const DM_Z &equal);					//������������� � ��������� ���������� ������� � ��������� ������
	DM_Z operator* (const int &mul) const;				//��������� ������ ����� �� ����� ����� (int)
};

// ==================================== ������������ �����  ==================================== 

class DM_Q
{
public:
	DM_Z a;			//���������
	DM_Z b;			//����������

public:
	DM_Q();												//�������������� �����������
	DM_Q(DM_Z a, DM_Z b);								//����������� �������� �����
	~DM_Q();											//����������
	void print();										//����� ����� �� �����
	DM_Q operator* (const int &mul) const;
};

// ==================================== �������  ==================================== 

class DM_P
{
public:
	DM_Q *c;			//������ �������������
	unsigned short m;	//���������� �������������

public:
	DM_P();										//�������������� �����������
	DM_P(DM_Q *a, unsigned short size);			//����������� �������� ������������
	~DM_P();									//����������
	DM_Q operator [] (unsigned short i);		//�������� ������ n-�� �����
	void print();								//����� ����� �� �����
};


