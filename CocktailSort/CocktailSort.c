#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 

//������ ������ �������� ������� �� ����� ��������� � ��������� ������. ���� 3
// 2. *����������� ��������� ����������.

#define MaxN 10000


void swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// ������������� ������
void print(int N, int * a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}

void BuildAr(int *x, int  size)
{

	srand(time(NULL)); // ������������� �������� ��������� �����.
	int i;
	for (i = 0; i < size; i++)
	{

		x[i] = rand() % 100;     //��������� ������ ���������� ������� �� 0 �� 99

	}

}

void CocktailSort(int *x, int size)   // ��������� ����������
{
	int left = 0;
	int right = size - 1;
	int count = 0; // ����� ������� ���������� ��������

	while (left <= right)
	{
		for (int i = 0; i < right; i++)
		{
			count++;
			if (x[i] > x[i + 1])
				swap(&x[i], &x[i+1]);
		}
		right--;
		for (int i = right; i > left; i--)
		{
			count++;
			if (x[i - 1] > x[i])
			{
				swap(&x[i], &x[i - 1]);
			}
		}
		left++;
	}
	
	printf(" \n");
	printf("Count after coktail sort: %d \n", count); // ������� ������� �� �����
}


int main(int argc, char * argv[]) {
	char *locale = setlocale(LC_ALL, "");

	int a[MaxN]; // ������ ������ ������������� �������
	int N = MaxN;
	BuildAr(a, N);

	puts("Array before coktail sort");
	print(MaxN, a);
	getch();

	CocktailSort(a, MaxN);
	puts("Array after coktail sort");
	print(MaxN, a);
	getch();







	return 0;
}
