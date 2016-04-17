#include "stdafx.h"
#include "DataTypes.h"
#include <math.h>
//����������� ����������
#include "Sidorov.h"

// ==================================== ����������� �����  ==================================== 

//�������������� �����������
DM_N::DM_N()
{
	a = 0;
	n = 0;
}

//����������� �������� �����
DM_N::DM_N(unsigned i)
{
	short count = 0;
	unsigned temp = i;

	while (temp || !count)
	{
		temp /= 10;
		count++;
	}

	a = new unsigned short[count];

	int current = 0;
	while (i || !current)
	{
		a[current] = i % 10;
		i /= 10;
		current++;
	}
	n = count;
}

//����������� �����
DM_N::DM_N(const DM_N &obj)
{
	this->n = obj.n;

	this->a = new unsigned short[obj.n];
	for (int i = 0; i < obj.n; i++)
		this->a[i] = obj.a[i];
}

//����������
DM_N::~DM_N()
{
	delete[] a;
}

//����� ����� �� �����
void DM_N::print()
{
	for (int i = n - 1; i >= 0; i--)
		printf("%d", a[i]);
}

//�������� ������ n-�� �����
unsigned short DM_N::operator [] (unsigned short i)
{
	return a[i];
}

//��������
DM_N DM_N::operator + (const DM_N &add) const
{
	DM_N *result = new DM_N;

	short maxLen, minLen;
	short maxIs;

	if (this->n > add.n)
	{
		maxIs = 2;
		maxLen = this->n;
		minLen = add.n;
	}
	else
	{
		maxIs = 1;
		minLen = this->n;
		maxLen = add.n;
	}

	short temp = 0;

	for (int i = 0; i < maxLen; i++)
	{
		temp /= 10;
		if (i < minLen)
			temp += this->a[i] + add.a[i];
		else
			if (maxIs == 2)
				temp += this->a[i];
			else
				temp += add.a[i];
	}

	if (temp >= 10)
	{
		temp = 0;
		result->a = new unsigned short[maxLen + 1];
		for (int i = 0; i < maxLen; i++)
		{
			if (i < minLen)
				temp += this->a[i] + add.a[i];
			else
				if (maxIs == 2)
					temp += this->a[i];
				else
					temp += add.a[i];
			result->a[i] = temp % 10;
			temp /= 10;
		}
		result->a[maxLen] = temp % 10;
		result->n = maxLen + 1;
	}
	else
	{
		temp = 0;
		result->a = new unsigned short[maxLen];
		for (int i = 0; i < maxLen; i++)
		{
			if (i < minLen)
				temp += this->a[i] + add.a[i];
			else
				if (maxIs == 2)
					temp += this->a[i];
				else
					temp += add.a[i];
			result->a[i] = temp % 10;
			temp /= 10;
		}
		result->n = maxLen;
	}

	return *result;
}

//������������ � ��������� ������ �������
void DM_N::operator= (const DM_N &equal) 
{
	if (this->a)
		delete[] this->a;

	this->a = new unsigned short[equal.n];
	this->n = equal.n;
	for (int i = 0; i < equal.n; i++)
		this->a[i] = equal.a[i];
}

//��������� ������������ ����� �� ����������� ����� (int)
DM_N DM_N::operator* (const unsigned &mul) const
{
	if (mul == 0)
		return DM_N(0);

	unsigned r = 0;			//�������

	short sizeOfMul = 0;	//������ ���������������
	unsigned temp = mul;
	while (temp)
	{
		temp /= 10;
		sizeOfMul++;
	}

	unsigned short *rawResult = new unsigned short[this->n + sizeOfMul];
	for (int i = 0; i < this->n + sizeOfMul; i++)
		rawResult[i] = 0;

	short current = 0;			//����� �������� �������
	do							//���������� ��������� � ��������� ������� �� ������� �� 10 � ������� ������
	{
		r += this->a[current] * mul;
		rawResult[current] = r % 10;
		r /= 10;
		current++;
	} while (r || current < this->n);

	while (r)	//���� ������� ��� �������, ���������� ���
	{
		rawResult[current] = r % 10;
		r /= 10;
		current++;
	}

	short numberOfZeros = 0;	//���������� ���������� �����
	for (int i = this->n + sizeOfMul - 1; i >= 0 && rawResult[i] == 0; i--, numberOfZeros++);

	//�������� ������ ���������� ������
	unsigned short *finalResult = new unsigned short[this->n + sizeOfMul - numberOfZeros];
	for (int i = 0; i < this->n + sizeOfMul - numberOfZeros; i++)
		finalResult[i] = rawResult[i];

	delete[] rawResult;

	DM_N Nresult;
	Nresult.a = finalResult;
	Nresult.n = this->n + sizeOfMul - numberOfZeros;

	return Nresult;
}

//��������� ������������ ����� �� ����������� ����� (DM_N) 
DM_N DM_N::operator* (const DM_N &mul) const
{
	if (this->a[0] == 0 && this->n == 1 || mul.a[0] == 0 && mul.n == 1)
		return DM_N(0);

	unsigned short current = 0;					//������� ������ ���������

	DM_N res;									//�����, ���������� ���������� �� ������� ������ ���������
	res.n = this->n + mul.n;
	res.a = new unsigned short[res.n];
	for (int i = 0; i < res.n; i++)
		res.a[i] = 0;
	
	DM_N rawResult;								//������������� ���������
	rawResult.n = this->n + mul.n;
	rawResult.a = new unsigned short[rawResult.n];
	for (int i = 0; i < rawResult.n; i++)
		rawResult.a[i] = 0;

	while (current < mul.n)						//���������� ��������
	{
		for (short i = 0; i < this->n; i++)
			res =  res + this->a[i] * mul.a[current] * (unsigned int)pow(10, i);
		MUL_Nk_N(res, current);
		rawResult = rawResult + res;
		for (int i = 0; i < res.n; i++)
			res.a[i] = 0;
		++current;
	}
	
	DM_N result;								//��������� ���������

	if (rawResult[rawResult.n - 1] == 0)				//�������, ���� �� ���������� ����
		result.n = rawResult.n - 1;
	else
		result.n = rawResult.n;

	result.a = new unsigned short[result.n];	//���������� �������� ���������
	for (int i = 0; i < result.n; i++)
		result.a[i] = rawResult.a[i];
	
	return result;
}

// ==================================== ����� �����  ==================================== 

//�������������� �����������
DM_Z::DM_Z()
{
	b = 0;
	a = 0;
	n = 0;
}

//����������� �������� �����
DM_Z::DM_Z(int i)
{
	if (i < 0)
	{
		b = 1;
		i *= -1;
	}
	else
	{
		b = 0;
	}

	short count = 0;
	unsigned temp = i;

	while (temp || !count)
	{
		temp /= 10;
		count++;
	}

	a = new unsigned short[count];

	int current = 0;
	while (i || !current)
	{
		a[current] = i % 10;
		i /= 10;
		current++;
	}
	n = count;
}

//����������� �����
DM_Z::DM_Z(const DM_Z &obj)
{
	this->b = obj.b;
	this->n = obj.n;

	this->a = new unsigned short[obj.n];
	for (int i = 0; i < obj.n; i++)
		this->a[i] = obj.a[i];
}

//����� ����� �� �����
void DM_Z::print()
{
	if (b)
		printf("-");
	for (int i = n - 1; i >= 0; i--)
		printf("%d", a[i]);
}

//����������
DM_Z::~DM_Z()
{
	delete[] a;
}

//�������� ������ n-�� �����
unsigned short DM_Z::operator[] (unsigned short i)
{
	return a[i];
}

//������������� � ��������� ���������� ������� � ��������� ������
void DM_Z::operator= (const DM_Z &equal)
{
	this->b = equal.b;
	this->n = equal.n;

	if (this->a)
		delete[] this->a;

	this->a = new unsigned short[this->n];
	for (int i = 0; i < this->n; i++)
		this->a[i] = equal.a[i];
}

//��������� ������ ����� �� ����� ����� (int)
DM_Z DM_Z::operator* (const int &mul) const
{
	DM_Z result; //���������

	if (mul == 0)
		return DM_Z(0);


	int tempMul = mul;
	if (tempMul < 0)		//������ ���� ����������
	{
		tempMul *= -1;
		result.b = (this->b? 0 : 1);
	}
	else
	{
		result.b = (this->b ? 1 : 0);
	}

	unsigned r = 0;			//�������

	short sizeOfMul = 0;	//������ ���������������
	int temp = tempMul;
	while (temp)
	{
		temp /= 10;
		sizeOfMul++;
	}

	unsigned short *rawResult = new unsigned short[this->n + sizeOfMul];
	for (int i = 0; i < this->n + sizeOfMul; i++)
		rawResult[i] = 0;

	short current = 0;			//����� �������� �������
	do							//���������� ��������� � ��������� ������� �� ������� �� 10 � ������� ������
	{
		r += this->a[current] * tempMul;
		rawResult[current] = r % 10;
		r /= 10;
		current++;
	} while (r || current < this->n);

	while (r)	//���� ������� ��� �������, ���������� ���
	{
		rawResult[current] = r % 10;
		r /= 10;
		current++;
	}

	short numberOfZeros = 0;	//���������� ���������� �����
	for (int i = this->n + sizeOfMul - 1; i >= 0 && rawResult[i] == 0; i--, numberOfZeros++);

	//�������� ������ ���������� ������
	unsigned short *finalResult = new unsigned short[this->n + sizeOfMul - numberOfZeros];
	for (int i = 0; i < this->n + sizeOfMul - numberOfZeros; i++)
		finalResult[i] = rawResult[i];

	delete[] rawResult;

	result.a = finalResult;
	result.n = this->n + sizeOfMul - numberOfZeros;

	return result;
}

// ==================================== ������������ �����  ==================================== 

//�������������� �����������
DM_Q::DM_Q()
{
	a = DM_Z();
	b = DM_Z();
}

//����������� �������� �����
DM_Q::DM_Q(DM_Z a, DM_Z b)
{
	DM_Q::a = a;
	DM_Q::b = b;
	if (a.b == 1 && b.b == 1)
	{
		DM_Q::a.b = 0;
		DM_Q::b.b = 0;
	}
	else
		if (b.b == 1)
		{
			DM_Q::a.b = 1;
			DM_Q::b.b = 0;
		}

}

//����������
DM_Q::~DM_Q()
{
}

//����� ����� �� �����
void DM_Q::print()
{
	if (b.n == 1 && b.a[0] == 1)
		a.print();
	else
		if (a.n == 1 && a.a[0] == 0)
			printf("0");
		else
		{
			printf("(");
			a.print();
			printf("/");
			b.print();
			printf(")");
		}
}

//��������� ������������� ����� �� ����� ����� (int)
DM_Q DM_Q::operator* (const int &mul) const
{
	DM_Q result;
	result.a = this->a * mul;
	result.b = this->b;
	return result;

}

// ==================================== �������  ==================================== 

//�������������� ������������
DM_P::DM_P()
{
	c = 0;
	m = 0;
}

//����������� � �������� ���������
DM_P::DM_P(DM_Q *a, unsigned short size)
{
	c = new DM_Q[size];
	m = size - 1;
	for (int i = 0; i < size; i++)
		c[i] = a[i];
}

//�������� ������ ������������
DM_Q DM_P::operator [] (unsigned short i)
{
	return c[i];
}

//����� �� �����
void DM_P::print()
{
	for (int i = 0; i <= m; i++)
	{
		if (c[i].a.n != 1 || c[i].a.a[0] != 0)
		{
			c[i].print();
			if (i == 0)
				printf("");
			else
				if(i == 1)
					printf("x");
				else
					if(i != m)
						printf("x^%d", i);
					else
						printf("x^%d", i);

			if (i != m)
				if (c[i + 1].a.b == 0)
					printf("+");
		}
	}
}

//����������
DM_P::~DM_P() 
{
	delete[] c;
}

