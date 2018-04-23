#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 

//Брижак Андрей Домашнее задание по курсу Алгоритмы и структуры данных. Урок 3
//3. Реализовать бинарный алгоритм поиска в виде функции, которой передаётся
//отсортированный массив.Функция возвращает индекс найденного элемента или −1, если
//элемент не найден.

#define MaxN 100


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

	while (left <= right)
	{
		for (int i = 0; i < right; i++)
		{
			count++;
			if (x[i] > x[i + 1])
				swap(&x[i], &x[i + 1]);
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
	printf("Count after coktail sort: %d \n", count); // Выводим счётчик на экран
}

int binarysearch(int a, int *mass, int n)  //функция бинарного поиска
{
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mass[middle])
			high = middle - 1;
		else if (a > mass[middle])
			low = middle + 1;
		else
			return middle;
	}
	return -1;
}

int main(int argc, char * argv[]) {
	char *locale = setlocale(LC_ALL, "");

	int a[MaxN]; // создаём массив максимального размера
	int N = MaxN;
	int res_binarysearch;
	BuildAr(a, N);

	puts("Array before coktail sort");
	print(MaxN, a);
	getch();

	CocktailSort(a, MaxN);
	puts("Array after coktail sort");
	print(MaxN, a);
	getch();

	printf(" \n");
	int value;
	printf("Input value for search:");
	scanf("%d", &value);
	res_binarysearch = binarysearch(value, a, N);
	if (res_binarysearch != -1)
		printf("Index:%d Value:%d", res_binarysearch, a[res_binarysearch]);
	else
		printf("Value not found");
	getch();
	
	return 0;
}
