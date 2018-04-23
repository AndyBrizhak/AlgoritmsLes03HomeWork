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
//Брижак Андрей Домашнее задание по курсу Алгоритмы и структуры данных. Урок 3
//4. *Подсчитать количество операций для каждой из сортировок для 100, 10000 и 1000000
//элементов.Представьте данные в виде таблицы.Подсчитывать только операции
//перестановки и время сортировки.

void swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// Распечатываем массив
void print(int N, int * a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}

void BuildAr(int *x, int  size)
{

	srand(time(NULL)); // Инициализация счетчика случайных чисел.
	int i;
	for (i = 0; i < size; i++)
	{

		x[i] = rand() % 100;     //заполняем массив случайными числами от 0 до 99

	}
}

void CocktailSort(int *x, int size)   // шейкерная сортировка
	{
		int left = 0;
		int right = size - 1;
		int count = 0; // Ввели счётчик количества операций
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

		printf(" \n");
		printf("Count after coktail sort: %d \n", count); // Выводим счётчик на экран
		printf("coktail sort выполнялся %f секунд\n", timesort);
	}

	void BublesSort(int *x, int size)   // простая сортировка
	{
		int count = 0; // Ввели счётчик количества операций
		int j = 0;
		int k = 0;
		int n = size;
		for (k = 0; k < n; k++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (x[j] > x[j + 1])
				{
					count++;
					swap(&x[j], &x[j + 1]);
				}
			}
		}
		printf(" \n");
		printf("Count after simple buble sort: %d \n", count); // Выводим счётчик на экран
	}

	int main(int argc, char * argv[])
	{
		char *locale = setlocale(LC_ALL, "");

		int a[Max100]; // создаём массив максимального размера
		int N = Max100;
		BuildAr(a, N);

		puts("Array before coktail sort");
		print(Max100, a);
		getch();

		CocktailSort(a, Max100);
		puts("Array after coktail sort");
		print(Max100, a);
		getch();


		return 0;
	}