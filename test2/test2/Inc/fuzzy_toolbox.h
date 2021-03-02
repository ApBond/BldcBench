#ifndef FUZZY_TOOLBOX_H
#define FUZZY_TOOLBOX_H

#include "math.h"
#include "stdint.h"

#define TRIANGLE 0
#define BALL 1
#define TRAPEZE 2
#define TYPE_S 3
#define TYPE_Z 4

#define MU_MAX 10000

typedef struct //���� �������� ����������
{
	int16_t min;//������ ������
	int16_t max;//����� ������
	int16_t pic;//�������� ��� ������������
	char shape;//����� ����� ������ �����
} term;

typedef struct //������� �������� ������
{
	int16_t mu;//�������������� � ����� ���������� 
	char term;//����� ����� � ������ ����������
} rull;

int16_t limitedSum(int16_t A, int16_t B);//������������ ����� (�����-�� ������)
int16_t fuzzyOr(int16_t A, int16_t B);//�������� ���
int16_t fuzzyAnd(int16_t A, int16_t B);//�������� �
int16_t fuzzyNot(int16_t A);//�������� ��

/*����������� � ��� �������� ������*/
int16_t fuzzifier(term Term, int16_t A);//������� ������������
int16_t triangle(int16_t min, int16_t max, int16_t pic, int16_t A);
int16_t ball(int16_t min, int16_t max, int16_t A);
int16_t trapeze(int16_t min, int16_t max, int16_t A);
int16_t typeS(int16_t min, int16_t max, int16_t A);
int16_t typeZ(int16_t min, int16_t max, int16_t A);

/*������������� � �������� ��� �������� ������*/
int16_t defuzzifier(term termB, int16_t muB);//������� ��������������
int16_t detriangle(int16_t min, int16_t max, int16_t pic, int16_t A);
int16_t deball(int16_t min, int16_t max, int16_t A);
int16_t detrapeze(int16_t min, int16_t max, int16_t A);
int16_t detypeS(int16_t min, int16_t max, int16_t A);
int16_t detypeZ(int16_t min, int16_t max, int16_t A);

/*�������� ���������� �����*/
int16_t Mamdany_Singlton(rull* rulls, term *termB, char lenRulls);
/*���� ����� ������ �������. ����� ����� �������� �� ���� ��� ���� ������� ��� ������-������ (�� ���� ����� �� ����)*/

#endif