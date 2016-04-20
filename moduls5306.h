#pragma once

#include "stdafx.h"
#include "DataTypes.h"

#ifndef moduls5306
#define moduls5306

//===Сидоров===
int COM_NN_D(DM_N n1, DM_N n2);					//Функция для сравнения двух натуральных чисел
void MUL_Nk_N(DM_N &obj, unsigned short k);		//Функция для умножения натурального числа на 10 в степени k
DM_P DER_P_P(const DM_P &obj);					//Производная многочлена

//===Ершов===
DM_Z TRANS_N_Z(DM_N nat);						//Функция преобразования натурального числа в целое 
short unsigned int POZ_Z_D(DM_Z cel);			//Функция определения положительности числа
void MUL_Zm_Z(DM_Z *cel);						//Функция умножения целого числа на -1

//=== Янаки ===
unsigned short DEG_P_N(DM_P *P);				//Функция определения степени многочлена(готова, не тестил)
DM_P MULL_PP_P(DM_P *P1, DM_P *P2);				//Функция умножения многочленов(готова, не тестил)
DM_Q FAC_P_PQ(DM_P *P, DM_Q *k);				//Функция вынесения из многочлена НОК знаменателей коэффициентов и НОД числителей(не готова)
#endif