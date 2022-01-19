#include <stdio.h>

#define A_ROW_SIZE 2
#define A_COL_SIZE 2 
#define B_ROW_SIZE 3
#define B_COL_SIZE 3
#define C_ROW_SIZE 2
#define C_COL_SIZE 3

/*
���� 6-4. ����� ����
n*m ��� A�� r*s ��� B�� �ְ�, m=r�� ��, n*s ��� A*B = [c_ij]
*/
void error(int, int, int);  //m == r
void mulMatrix(int **, int **, int **, int, int, int);

/*
*********************************** CHALLENGE 5 **********************************
	  ��ó : ��ǻ�� ������ Ű��� �̻���� ������ �Ѻ���ī���� p.187_ex_6-4
**********************************************************************************
*/

int main(int argc, char* argv[])
{

	int A[A_ROW_SIZE][A_COL_SIZE] = { {1,3}, {4,6} };
	int B[B_ROW_SIZE][B_COL_SIZE] = { {1,0,2}, {9,3,8}, {4,7,5} };
	int C[C_ROW_SIZE][C_COL_SIZE] = { {0,6,1}, {3,5,2} };

	error(1, A_COL_SIZE, B_ROW_SIZE); //1) A*B 
	error(2, B_COL_SIZE, A_ROW_SIZE); //2) B*A
	error(3, A_COL_SIZE, C_ROW_SIZE); //3) A*C
	error(4, C_COL_SIZE, A_ROW_SIZE); //4) C*A
	error(5, B_COL_SIZE, C_ROW_SIZE); //5) B*C
	error(6, C_COL_SIZE, B_ROW_SIZE); //6) C*B

	int AmulC[A_ROW_SIZE][C_COL_SIZE];
	int CmulB[C_ROW_SIZE][B_COL_SIZE];
	
	int* *p1 = A;
	int* *p2 = C;
	int* *p3 = B;

	int* *p = AmulC;
	mulMatrix(p1, p2, p, A_ROW_SIZE, A_COL_SIZE, C_COL_SIZE);
	p = CmulB;
	mulMatrix(p2, p3, p, C_ROW_SIZE, C_COL_SIZE, B_COL_SIZE);
	return 0;
}
void mulMatrix(int* *p1, int* *p2, int* *p, int rowSize1, int colSize1, int colSize2)
{
	int i = 0, j = 0, k = 0, sum = 0;

	for (i = 0; i < rowSize1; i++)
	{
		for (j = 0; j < colSize2; j++)
		{
			sum = 0;
			k = 0;
			while (k < colSize1)
			{
				sum += (p1[i][k] * p2[k][j]);
				k++;
			}
			p[i][j] = sum;
			printf(" %02d ", p[i][j]);
		}
		putchar('\n');
	}
}
void error(int num, int num1, int num2)
{
	if (num1 == num2)
	{
		// mulMatrix �Լ��� �̵�
	}
	else
		fprintf(stderr, "[%d�� ����] ù��° ����� ���� ũ�� %d��(��) �ι�°���� ũ�� %d��(��) �ٸ��ϴ�! ������ �� �� �����ϴ�!\n", num, num1, num2);
}