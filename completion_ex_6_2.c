#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 4 //��
#define COL_SIZE 4 //��

void error(int, int, int, int); //����� ������ ������ �� ����� ũ�Ⱑ ���ƾ߸� ������ �� �ִ�.
void plus_func(int A[][COL_SIZE], int B[][COL_SIZE], int(*p)[COL_SIZE], int, int); //���ϱ�
void minus_func(int A[][COL_SIZE], int B[][COL_SIZE], int(*p)[COL_SIZE], int, int); //����

/*
******************************* CHALLENGE 1 ********************************
	  ��ó : ��ǻ�� ������ Ű��� �̻���� ������ �Ѻ���ī���� p.187_ex_6-2
****************************************************************************
*/

int main(void)
{

	int(*p)[COL_SIZE];
	int A[ROW_SIZE][COL_SIZE] = {
		{2, 1, 4, 0}, {-7, 3, 6, 1},{8, -4, -2, 3},{1, 9, 4, -2}
	};
	int B[ROW_SIZE][COL_SIZE] = {
		{7, -1, 2, 4}, {2, 8, -5, 1}, {-3, -4, 2, -2}, {9, 6, -2, 0}
	};

	int AplusB[ROW_SIZE][COL_SIZE];
	int AminusB[ROW_SIZE][COL_SIZE];
	int BminusA[ROW_SIZE][COL_SIZE];

	p = AplusB;
	error(sizeof(A[0]) / sizeof(int), sizeof(A) / sizeof(A[0]), sizeof(B[0]) / sizeof(int), sizeof(B) / sizeof(B[0]));
	plus_func(A, B, p, ROW_SIZE, COL_SIZE);

	p = AminusB;
	error(sizeof(A[0]) / sizeof(int), sizeof(A) / sizeof(A[0]), sizeof(B[0]) / sizeof(int), sizeof(B) / sizeof(B[0]));
	minus_func(A, B, p, ROW_SIZE, COL_SIZE);

	p = BminusA;
	error(sizeof(B[0]) / sizeof(int), sizeof(B) / sizeof(B[0]), sizeof(A[0]) / sizeof(int), sizeof(A) / sizeof(A[0]));
	minus_func(B, A, p, ROW_SIZE, COL_SIZE);

	/* A+B �׽�Ʈ
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)		printf("%5d\t", AplusB[i][j]);
		putchar('\n');
	}
	*/
	return 0;
}

void plus_func(int A[][COL_SIZE], int B[][COL_SIZE], int(*p)[COL_SIZE], int rowSize, int colSize)
{
	int i, j;
	for (i = 0; i < rowSize; i++)
	{
		for (j = 0; j < colSize; j++)		p[i][j] = A[i][j] + B[i][j];
	}
}

void minus_func(int A[][COL_SIZE], int B[][COL_SIZE], int(*p)[COL_SIZE], int rowSize, int colSize)
{
	int i, j;
	for (i = 0; i < rowSize; i++)
	{
		for (j = 0; j < colSize; j++)		p[i][j] = A[i][j] - B[i][j];
	}
}

void error(int rowSize1, int colSize1, int rowSize2, int colSize2)
{
	if (rowSize1 != rowSize2 || colSize1 != colSize2)
	{
		fprintf(stderr, "����� ������ ������ �� ����� ũ�Ⱑ ���ƾ߸� ������ �� �ֽ��ϴ�.");
		exit(1);
	}
}