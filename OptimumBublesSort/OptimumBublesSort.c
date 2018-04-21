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
	
	srand(time(NULL)); // ������������� �������� ��������� �����.
	int i;
	for (i = 0; i < N; i++)
	{
		
		a[i] = rand() % 100;     //��������� ������ ���������� ������� �� 0 �� 99
		
	}
	
}

int main(int argc, char * argv[]) {
	char *locale = setlocale(LC_ALL, "");
	
	int a[MaxN]; // ������ ������ ������������� �������
	int N =MaxN;
	BuildAr(N, a);
	FILE *in;

	//in = fopen("d:\\temp\\data.txt", "w");
	in = fopen("data.txt", "w");
	if (in == NULL)
	{
		puts("File not found");
		getch();
	}
	//fscanf(in, "%i", &N);
	fprintf(in, "%i", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		fprintf(in, "%i", &a[i]);
	}
	fclose(in);
	//fscanf(in, "%i", &N);
	//	fscanf(in, "%i", &a[i]);
	//fprint(in, "%i", &a[i]);
	//fclose(in);

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