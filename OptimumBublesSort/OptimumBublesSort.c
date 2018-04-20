#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> // Для использования генератора случайных чисел

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




int main(int argc, char * argv[]) {
	char *locale = setlocale(LC_ALL, "");
	
	int a[MaxN]; // создаём массив максимального размера
	int N =100;
	//FILE * in;
	//in = fopen("d:\\temp\\data.txt", "r");
	//fscanf(in, "%i", &N);
	srand(time(NULL)); // Инициализация счетчика случайных чисел.
	int i;
	for (i = 0; i < N; i++)
	{
	//	fscanf(in, "%i", &a[i]);
		a[i] = rand() % 100;     //заполняем массив случайными числами от 0 до 99
	}
	//fclose(in);

	puts("Array before sort");
	print(N, a);
	getch();

	int j = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N - 1; j++)
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
	puts("Array after sort");
	print(N, a);
	getch();
	return 0;
}