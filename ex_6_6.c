/*
*********************************** CHALLENGE 1 **********************************
	  ��ó : ��ǻ�� ������ Ű��� �̻���� ������ �Ѻ���ī���� p.199_ex_6-6
		2��, 3�� ���簢����� ��Ľ��� ���Ͽ���.
**********************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>

#define SQURE_MATRIX_2 2
#define SQURE_MATRIX_3 3

int det2(int, int[][2]);
int det3(int, int[][3]);

void print(int, int);

void main()
{
	int A[SQURE_MATRIX_2][SQURE_MATRIX_2] = { {3, 1}, {2,-1} };
	int B[SQURE_MATRIX_3][SQURE_MATRIX_3] = { {3, -1, -2}, {-4, 2, 1}, {1, 4, -3} };
	int defA = det2(SQURE_MATRIX_2, A);
	print(SQURE_MATRIX_2, defA);
	int defB = det3(SQURE_MATRIX_3, B);
	print(SQURE_MATRIX_3, defB);
}
int det2(int size, int matrix[][2])
{
	int i, j, p = 1, q = 1;
	//2��
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			if (i == j) p *= matrix[i][j];
			else if (j == (size - 1 - i)) q *= matrix[i][j];
	}
	return p - q;
}

int det3(int size, int matrix[][3])
{
	//�����
	int i, j;
	int value = size - 1;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{

		}
	}
	
	
}
void print(int squre_matrix, int def_num)
{
	printf("%d�� ��Ľ��� %d�Դϴ�.\n",squre_matrix,  def_num);
}