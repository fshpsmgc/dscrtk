#pragma once

#include "stdafx.h"
#include "DataTypes.h"

#ifndef moduls5306
#define moduls5306

//===�������===
int COM_NN_D(DM_N n1, DM_N n2);					//������� ��� ��������� ���� ����������� �����
void MUL_Nk_N(DM_N &obj, unsigned short k);		//������� ��� ��������� ������������ ����� �� 10 � ������� k
DM_P DER_P_P(const DM_P &obj);					//����������� ����������

//===�����===
DM_Z TRANS_N_Z(DM_N nat);						//������� �������������� ������������ ����� � ����� 
short unsigned int POZ_Z_D(DM_Z cel);			//������� ����������� ��������������� �����
void MUL_Zm_Z(DM_Z *cel);						//������� ��������� ������ ����� �� -1

#endif