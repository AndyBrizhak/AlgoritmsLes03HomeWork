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

Par CocktailSort(int *x, int size)   // шейкерная сортировка
	{
	Par Parametrs;
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
		Parametrs.size = size;
		Parametrs.count = count;
		Parametrs.time = timesort;
		printf(" \n");
		printf("Count after coktail sort: %d \n", count); // Выводим счётчик на экран
		printf("coktail sort выполнялся %f секунд\n", timesort);
		return Parametrs;
		
	}

Par BublesSort(int *x, int size)   // простая сортировка
	{
	Par Parametrs;
		int count = 0; // Ввели счётчик количества операций
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
		printf("Count after simple buble sort: %d \n", count); // Выводим счётчик на экран
		printf("Bubles sort выполнялся %f секунд\n", timesort);
		return Parametrs;
	}

	int main(int argc, char * argv[])
	{
		char *locale = setlocale(LC_ALL, "");

		int a[Max100]; // создаём массив максимального размера
		int N = Max100;
		BuildAr(a, N);

		FILE *out100;
		out100 = fopen("data.txt", "w");
		if (out100 == NULL)
		{
			puts("File not found");
			getch();
		}
		//fscanf(in, "%i", &N);
		fprintf(out100, "%i", &N);
		int i;
		for (i = 0; i < N; i++)
		{
			fprintf(out100, "%i", a[i]);
		}
		fclose(out100);
		

		//int b[Max100]; // создаём копию неотсортированного массива максимального размера
		int x = Max100;
		///*int i;*/
		//for (i = 0; i < x; i++)
		//{
		//	b[i] = a[i];
		//}

		puts("Array before coktail sort");
		print(Max100, a);
		getch();
		Par cocktailsort100 = CocktailSort(a, Max100);
		puts("Array after coktail sort");
		print(Max100, a);
		printf(" \n");
		printf("Size array for cocktail sort: %d \n", cocktailsort100.size);
		printf("Count after coktail sort: %d \n", cocktailsort100.count); // Выводим счётчик на экран
		printf("coktail sort выполнялся %f секунд\n", cocktailsort100.time);
		getch();

		
		//for (i = 0; i < x; i++)
		//{
		//	b[i] = a[i];
		//}

		FILE *in;
		in = fopen("data.txt", "r");
		if (in == NULL)
		{
			puts("File not found");
			getch();
		}
		fscanf(in, "%i", &N);
		//fprintf(in, "%i", &N);
		//int i;
		for (i = 0; i < N; i++)
		{
			fscanf(in, "%i", &a[i]);
		}
		fclose(in);
		


		Par bublessort100 = BublesSort(a, Max100);
		puts("Array after bubles sort");
		print(Max100, a);
		printf(" \n");
		printf("Size array for bubles sort: %d \n", bublessort100.size);
		printf("Count after simple buble sort: %d \n", bublessort100.count); // Выводим счётчик на экран
		printf("Bubles sort выполнялся %f секунд\n", bublessort100.time);
		getch();

		int a10000[Max10000]; // создаём массив максимального размера
		N = Max10000;
		BuildAr(a10000, N);

		int b10000[Max10000]; // создаём копию неотсортированного массива максимального размера
		x = Max10000;
		/*int i;*/
		for (i = 0; i < x; i++)
		{
			b10000[i] = a10000[i];
		}

		puts("Array before coktail sort");
		print(Max10000, a10000);
		getch();
		Par cocktailsort10000 = CocktailSort(b10000, Max10000);
		puts("Array after coktail sort");
		print(Max10000, b10000);
		printf(" \n");
		printf("Size array for cocktail sort: %d \n", cocktailsort10000.size);
		printf("Count after coktail sort: %d \n", cocktailsort10000.count); // Выводим счётчик на экран
		printf("coktail sort выполнялся %f секунд\n", cocktailsort10000.time);
		getch();

		for (i = 0; i < x; i++)
		{
			b10000[i] = a10000[i];
		}

		Par bublessort10000 = BublesSort(b10000, Max10000);
		puts("Array after bubles sort");
		print(Max10000, b10000);
		printf(" \n");
		printf("Size array for bubles sort: %d \n", bublessort10000.size);
		printf("Count after simple buble sort: %d \n", bublessort10000.count); // Выводим счётчик на экран
		printf("Bubles sort выполнялся %f секунд\n", bublessort10000.time);
		getch();

		//int a1000000[Max1000000]; // создаём массив максимального размера
		//N = Max1000000;
		//BuildAr(a1000000, N);

		//int b1000000[Max1000000]; // создаём копию неотсортированного массива максимального размера
		//x = Max1000000;
		///*int i;*/
		//for (i = 0; i < x; i++)
		//{
		//	b1000000[i] = a1000000[i];
		//}

		//puts("Array before coktail sort");
		//print(Max1000000, a1000000);
		//getch();
		//Par cocktailsort1000000 = CocktailSort(b1000000, Max1000000);
		//puts("Array after coktail sort");
		//print(Max1000000, b1000000);
		//printf(" \n");
		//printf("Size array for cocktail sort: %d \n", cocktailsort1000000.size);
		//printf("Count after coktail sort: %d \n", cocktailsort1000000.count); // Выводим счётчик на экран
		//printf("coktail sort выполнялся %f секунд\n", cocktailsort1000000.time);
		//getch();

		//for (i = 0; i < x; i++)
		//{
		//	b1000000[i] = a1000000[i];
		//}

		//Par bublessort1000000 = BublesSort(b1000000, Max1000000);
		//puts("Array after bubles sort");
		//print(Max1000000, b1000000);
		//printf(" \n");
		//printf("Size array for bubles sort: %d \n", bublessort1000000.size);
		//printf("Count after simple buble sort: %d \n", bublessort1000000.count); // Выводим счётчик на экран
		//printf("Bubles sort выполнялся %f секунд\n", bublessort1000000.time);
		//getch();


		return 0;
	}