#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> // Для использования генератора случайных чисел
#include "OptimumBublesSort.h"

// Определяем максимальный размер массива
#define MaxN 100

//Брижак Андрей Домашнее задание по курсу Алгоритмы и структуры данных. Урок 3
//1. Оптимизировать пузырьковую сортировку.Сопоставить количество операций сравнения
//оптимизированной и не оптимизированной программы.Написать функции сортировки,
//которые возвращают количество операций.


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

void OptBublesSort(int *x, int size)   // оптимизированная пузырьковая соритровка сортировка
{
	int count = 0; // Ввели счётчик количества операций
	int j = 0;
	int k = 0;
	int n = size;
	int min = k;
	for (k = 0; k < n; k++)
	{ 
		count++;
		for (j = 0; j < n - 1; j++)
		{
			if (x[j] > x[j + 1])
			{
				count++;
				swap(&x[j], &x[j + 1]);
				if (x[j] < x[min] )
				{
					/*count++;*/
					min = j;
				}
			}
		}
		if (x[k]<x[min])
		{
			count++;
			swap(&x[k], &x[min]);
		}
	}
	printf(" \n");
	printf("Count after optimum buble sort: %d \n", count); // Выводим счётчик на экран
}


void BublesSort(int *x, int size)   // простая сортировка
{
	int count = 0; // Ввели счётчик количества операций
	int j = 0;
	int k = 0;
	int n = size;
	for (k = 0; k < n; k++)
	{
		count++;
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

void BuildAr(int *x, int  size)
{
	
	srand(time(NULL)); // Инициализация счетчика случайных чисел.
	int i;
	for (i = 0; i < size; i++)
	{
		
		x[i] = rand() % 100;     //заполняем массив случайными числами от 0 до 99
		
	}
	
}

int main(int argc, char * argv[]) {
	char *locale = setlocale(LC_ALL, "");
	
	int a[MaxN]; // создаём массив максимального размера
	int N =MaxN;
	BuildAr(a, N);
	//FILE *in;
	////in = fopen("d:\\temp\\data.txt", "w");
	//in = fopen("data.txt", "w");
	//if (in == NULL)
	//{
	//	puts("File not found");
	//	getch();
	//}
	////fscanf(in, "%i", &N);
	//fprintf(in, "%i", &N);
	//int i;
	//for (i = 0; i < N; i++)
	//{
	//	fprintf(in, "%i", &a[i]);
	//}
	//fclose(in);
	////fscanf(in, "%i", &N);
	////	fscanf(in, "%i", &a[i]);
	////fprint(in, "%i", &a[i]);
	////fclose(in);

	int b[MaxN]; // создаём копию неотсортированного массива максимального размера
	int x = MaxN;
	int i;
	for (i = 0; i < x; i++)
	{
		b[i] = a[i];
	}
	//puts("Array b");
	//print(MaxN, b);
	//getch();


	puts("Array before sort");
	print(MaxN, a);
	getch();

	BublesSort(a, MaxN);
	puts("Array after simple bubles sort");
	print(MaxN, a);
	getch();

	puts("Array before optimum bubles sort");
	puts("Array b");
	print(MaxN, b);
	getch();

	OptBublesSort(b, MaxN);
	puts("Array after optimum bubles sort");
	print(MaxN, b);
	getch();
	
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