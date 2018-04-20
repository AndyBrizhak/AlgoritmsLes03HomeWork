#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> // ��� ������������� ���������� ��������� �����
#include "OptimumBublesSort.h"

// ���������� ������������ ������ �������
#define MaxN 100

//������ ������ �������� ������� �� ����� ��������� � ��������� ������. ���� 3
//1. �������������� ����������� ����������.����������� ���������� �������� ���������
//���������������� � �� ���������������� ���������.�������� ������� ����������,
//������� ���������� ���������� ��������.


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




void BublesSort(int  a[100])
{
	int j = 0;
	int k = 0;
	int n = MaxN;
	for (k = 0; k < n; k++)
		for (j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
}

void BuildAr(int N, int  a[100])
{
	/*FILE * in;
	in = fopen("d:\\temp\\data.txt", "w");*/
	/*in = fopen("\\data.txt", "r");*/
	//fscanf(in, "%i", &N);
	srand(time(NULL)); // ������������� �������� ��������� �����.
	int i;
	for (i = 0; i < N; i++)
	{
		//	fscanf(in, "%i", &a[i]);
		a[i] = rand() % 100;     //��������� ������ ���������� ������� �� 0 �� 99
		//fprint(in, "%i", &a[i]);
	}
	//fclose(in);
}

int main(int argc, char * argv[]) {
	char *locale = setlocale(LC_ALL, "");
	
	int a[MaxN]; // ������ ������ ������������� �������
	int N =MaxN;
	BuildAr(N, a);

	puts("Array before sort");
	print(MaxN, a);
	getch();

	BublesSort(a);
	puts("Array after simple sort");
	print(MaxN, a);
	getch();

	//int b[MaxN]; // ������ ������ ������������� �������
	//int x = MaxN;
	//int i = 0;
	//FILE * fp;
	//fp = fopen("d:\\temp\\data.txt", "r+");
	//for (i = 0; i< x; i++) 
	//{
	//	fscanf(fp, "%i", &b[i]);
	//	//	fscanf(in, "%i", &a[i]);
	//}
	//fclose(fp);

	//puts("Array before sort");
	//print(MaxN, b);
	//getch();

	return 0;
}