#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <time.h>
#include <io.h>
//#include <unistd.h>
#define Max100 100
#define Max10000 10000
#define Max1000000 1000000
//������ ������ �������� ������� �� ����� ��������� � ��������� ������. ���� 3
//4. *���������� ���������� �������� ��� ������ �� ���������� ��� 100, 10000 � 1000000
//���������.����������� ������ � ���� �������.������������ ������ ��������
//������������ � ����� ����������.

struct ParFunc
{
	int size;
	int count;
	double time;
};

typedef struct ParFunc Par;
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

Par CocktailSort(int *x, int size)   // ��������� ����������
	{
	Par Parametrs;
		int left = 0;
		int right = size - 1;
		int count = 0; // ����� ������� ���������� ��������
		clock_t start;
		clock_t finish;
		double timesort, timeswap;
		timesort = 0;
		while (left <= right)
		{
			for (int i = 0; i < right; i++)
			{
				
				if (x[i] > x[i + 1])
				{
					count++;
					start = clock();
				 swap(&x[i], &x[i + 1]);
				 finish = clock();
				 timeswap = (double)(finish - start) / CLOCKS_PER_SEC;
				 timesort += timeswap;
			    }
			}
			right--;
			for (int i = right; i > left; i--)
			{
				count++;
				if (x[i - 1] > x[i])
				{
					
					start = clock();
					swap(&x[i], &x[i - 1]);
					finish = clock();
					timeswap = (double)(finish - start) / CLOCKS_PER_SEC;
					timesort += timeswap;
					
				}
			}
			left++;
		}
		Parametrs.size = size;
		Parametrs.count = count;
		Parametrs.time = timesort;
		printf(" \n");
		printf("Count after coktail sort: %d \n", count); // ������� ������� �� �����
		printf("coktail sort ���������� %f ������\n", timesort);
		return Parametrs;
		
	}

Par BublesSort(int *x, int size)   // ������� ����������
	{
	Par Parametrs;
		int count = 0; // ����� ������� ���������� ��������
		int j = 0;
		int k = 0;
		int n = size;
		clock_t start;
		clock_t finish;
		double timesort, timeswap;
		timesort = 0;
		for (k = 0; k < n; k++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (x[j] > x[j + 1])
				{
					count++;
					start = clock();
					swap(&x[j], &x[j + 1]);
					finish = clock();
					timeswap = (double)(finish - start) / CLOCKS_PER_SEC;
					timesort += timeswap;
				}
			}
		}
		Parametrs.size = size;
		Parametrs.count = count;
		Parametrs.time = timesort;
		printf(" \n");
		printf("Count after simple buble sort: %d \n", count); // ������� ������� �� �����
		printf("Bubles sort ���������� %f ������\n", timesort);
		return Parametrs;
	}

	int main(int argc, char * argv[])
	{
		char *locale = setlocale(LC_ALL, "");

		int a[Max100]; // ������ ������ ������������� �������
		int N = Max100;
		BuildAr(a, N);

		int b[Max100]; // ������ ����� ������������������ ������� ������������� �������
		int x = Max100;
		int i;
		for (i = 0; i < x; i++)
		{
			b[i] = a[i];
		}

		puts("Array before coktail sort");
		print(Max100, a);
		getch();
		Par cocktailsort100 = CocktailSort(b, Max100);
		puts("Array after coktail sort");
		print(Max100, b);
		printf(" \n");
		printf("Size array for cocktail sort: %d \n", cocktailsort100.size);
		printf("Count after coktail sort: %d \n", cocktailsort100.count); // ������� ������� �� �����
		printf("coktail sort ���������� %f ������\n", cocktailsort100.time);
		getch();

		//int b[Max100]; // ������ ����� ������������������ ������� ������������� �������
		//int x = Max100;
		//int i;
		for (i = 0; i < x; i++)
		{
			b[i] = a[i];
		}

		Par bublessort100 = BublesSort(b, Max100);
		puts("Array after bubles sort");
		print(Max100, b);
		printf(" \n");
		printf("Size array for bubles sort: %d \n", cocktailsort100.size);
		printf("Count after simple buble sort: %d \n", bublessort100.count); // ������� ������� �� �����
		printf("Bubles sort ���������� %f ������\n", bublessort100.time);
		getch();


		return 0;
	}