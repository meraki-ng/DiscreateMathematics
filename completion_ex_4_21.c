#include <stdio.h>
#include <stdlib.h>
/*
	출처 : 컴퓨팅 사고력을 키우는 이산수학 개정판 박주미 지음 한빛아카데미 p.131_예제 4-21
	"자연수 m,n에 대해 m <= 36이고 n <= 36이면, m+n <= 72다"
*/

int p(unsigned int, unsigned int, unsigned int);			 
int q(unsigned int, unsigned int, int);			
int notq(unsigned int, unsigned int, int);
void error(int, int, int); 
void print(int, int, int, int);

int main()
{
	unsigned int m, n, max_num;
	printf("두 수와 최댓값 범위를 입력하세요(각 수는 띄어쓰기로 구분) : ");
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
	return (m <= size) & (n <= size); // 결과 1과1일때만 1반환 나머진 0
}
int q(unsigned int m, unsigned int n, int size)
{
	// m <= size + n <= size
	return (m + n <= (size * 2));
}
int notq(unsigned int m, unsigned int n, int size)
{
	//!(m+n <= (size * 2)) 따라서 (m + n) > (size * 2)
	return(m + n >= ((size * 2) + 1)) | ((m + n > (size * 2)));
}

void print(int num, int m, int n, int max_num)
{
	switch (num)
	{
	case 1 :
		printf("p^~q이다는 참이다.\n");
		break;
	case 2 :
		printf("p^~q \"자연수 %d, %d에 대해 %d <= %d이고 %d<=%d이면, %d + %d >= %d다\"는 거짓(F)이다.\n", m, n, m, max_num, n, max_num, m, n, ((max_num * 2) + 1));
		break;
	case 3 :
		printf("명제 p이면q\"자연수 %d %d에 대해 %d <= %d 이고 %d <= %d이면 %d + %d <= %d다\"는 참(T)이다.\n", m, n, m, max_num, n, max_num, m, n, (max_num * 2));
		break;
	case 4 :
		printf("p이면q이다는 거짓이다.\n");
		break;
	}
}
void error(int m, int n, int size)
{
	if (m <= 0 || n <= 0 || size <= 0)
	{
		fprintf(stderr, "각각 자연수여야합니다.");
		exit(1);
	}
}