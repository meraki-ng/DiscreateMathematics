#include <stdio.h>
#include <stdlib.h>
/*
	��ó : ��ǻ�� ������ Ű��� �̻���� ������ ���ֹ� ���� �Ѻ���ī���� p.131_���� 4-21
	"�ڿ��� m,n�� ���� m <= 36�̰� n <= 36�̸�, m+n <= 72��"
*/

int p(unsigned int, unsigned int, unsigned int);			 
int q(unsigned int, unsigned int, int);			
int notq(unsigned int, unsigned int, int);
void error(int, int, int); 
void print(int, int, int, int);

int main()
{
	unsigned int m, n, max_num;
	printf("�� ���� �ִ� ������ �Է��ϼ���(�� ���� ����� ����) : ");
	scanf_s("%d %d %d", &m, &n, &max_num);

	error(m, n, max_num);

	if (notq(m, n, max_num) & p(m, n, max_num))	print(1, m, n, max_num);
	else print(2, m, n, max_num);

	if (q(m, n, max_num) & p(m, n, max_num))	print(3, m, n, max_num);
	else print(4, m, n, max_num);

	return 0;
}
int p(unsigned int m, unsigned int n, unsigned int size)
{
	return (m <= size) & (n <= size); // ��� 1��1�϶��� 1��ȯ ������ 0
}
int q(unsigned int m, unsigned int n, int size)
{
	// m <= size + n <= size
	return (m + n <= (size * 2));
}
int notq(unsigned int m, unsigned int n, int size)
{
	//!(m+n <= (size * 2)) ���� (m + n) > (size * 2)
	return(m + n >= ((size * 2) + 1)) | ((m + n > (size * 2)));
}

void print(int num, int m, int n, int max_num)
{
	switch (num)
	{
	case 1 :
		printf("p^~q�̴ٴ� ���̴�.\n");
		break;
	case 2 :
		printf("p^~q \"�ڿ��� %d, %d�� ���� %d <= %d�̰� %d<=%d�̸�, %d + %d >= %d��\"�� ����(F)�̴�.\n", m, n, m, max_num, n, max_num, m, n, ((max_num * 2) + 1));
		break;
	case 3 :
		printf("���� p�̸�q\"�ڿ��� %d %d�� ���� %d <= %d �̰� %d <= %d�̸� %d + %d <= %d��\"�� ��(T)�̴�.\n", m, n, m, max_num, n, max_num, m, n, (max_num * 2));
		break;
	case 4 :
		printf("p�̸�q�̴ٴ� �����̴�.\n");
		break;
	}
}
void error(int m, int n, int size)
{
	if (m <= 0 || n <= 0 || size <= 0)
	{
		fprintf(stderr, "���� �ڿ��������մϴ�.");
		exit(1);
	}
}