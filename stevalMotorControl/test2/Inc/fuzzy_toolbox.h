#ifndef FUZZY_TOLLBOX_H
#define FUZZY_TOLLBOX_H

#define TRIANGLE 0
#define BALL 1
#define TRAPEZE 2
#define TYPE_S 3
#define TYPE_Z 4


typedef struct //���� �������� ����������
{
	float min;//������ ������
	float max;//����� ������
	char shape;//����� ����� ������ �����
}term;

typedef struct //������� �������� ������
{
	float mu;//�������������� � ����� ���������� 
	char term;//����� ����� � ������ ����������
}rull;

float fuzzyOr(float A, float B);//�������� ���
float fuzzyAnd(float A, float B);//�������� �
float fuzzyNot(float A);//�������� ��

/*����������� � ��� �������� ������*/
float fuzzifier(term Term, float A);//������� ������������
float triangle(float min, float max, float A);
float ball(float min, float max, float A);
float trapeze(float min, float max, float A);
float typeS(float min, float max, float A);
float typeZ(float min, float max, float A);

/*������������� � �������� ��� �������� ������*/
float defuzzifier(term termB, float muB);//������� ��������������
float detriangle(float min, float max, float A);
float deball(float min, float max, float A);
float detrapeze(float min, float max, float A);
float detypeS(float min, float max, float A);
float detypeZ(float min, float max, float A);

/*�������� ���������� �����*/
float Mamdany_Singlton(rull* rulls, term *termB, char lenRulls);
/*���� ����� ������ �������. ����� ����� �������� �� ���� ��� ���� ������� ��� ������-������ (�� ���� ����� �� ����)*/       
#endif