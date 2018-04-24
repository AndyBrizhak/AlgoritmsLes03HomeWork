//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <time.h>
#include <io.h>
#include <malloc.h>

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
		int i;
		int *a;
		a = (int*)malloc(Max100 * sizeof(int));
		//int a[Max100]; // создаём массив максимального размера
		int N = Max100;
		BuildAr(a, N);

		//FILE *out100;
		//out100 = fopen("data.txt", "w");
		//if (out100 == NULL)
		//{
		//	puts("File not found");
		//	getch();
		//}
		///*fprintf(out100, "% i", &N);*/
		
		//for (i = 0; i < N; i++)
		//{
		//	fprintf(out100, "%i ", a[i]);
		//}
		//fclose(out100);
				
		int x = Max100;
		
		puts("Array before coktail sort");
		print(Max100, a);
		getch();
		Par cocktailsort100 = CocktailSort(a, Max100);
		puts("Array after coktail sort");
		print(Max100, a);
		printf(" \n");
		printf("Size array for cocktail sort: %d \n", cocktailsort100.size);
		printf("Count after coktail sort: %d \n", cocktailsort100.count); 
		printf("coktail sort выполнялся %f секунд\n", cocktailsort100.time);
		getch();
				

		//FILE *in100;
		//in100 = fopen("data.txt", "r");
		//if (in100 == NULL)
		//{
		//	puts("File not found");
		//	getch();
		//}
		///*fscanf(in100, "%i ", &N);*/
		//for (i = 0; i < N; i++)
		//{
		//	fscanf(in100, "%i ", &a[i]);
		//}
		//fclose(in100);
		BuildAr(a, N);

		puts("Array before bubles sort");
		print(Max100, a);
		printf(" \n");
		getch();

		Par bublessort100 = BublesSort(a, Max100);
		puts("Array after bubles sort");
		print(Max100, a);
		printf(" \n");
		printf("Size array for bubles sort: %d \n", bublessort100.size);
		printf("Count after simple buble sort: %d \n", bublessort100.count); // Выводим счётчик на экран
		printf("Bubles sort выполнялся %f секунд\n", bublessort100.time);
		getch();
		free(a);

		

		int *b;
		b = (int*)malloc(Max10000 * sizeof(int));
		N = Max10000;
		BuildAr(b, N);

		/*FILE *out10000;
		out10000 = fopen("data.txt", "w");
		if (out10000 == NULL)
		{
			puts("File not found");
			getch();
		}
		fprintf(out10000, "%i", &N);
		for (i = 0; i < N; i++)
		{
			fprintf(out10000, "%i", b[i]);
		}
		fclose(out10000);*/
		
		puts("Array before coktail sort");
		print(Max10000, b);
		getch();
		Par cocktailsort10000 = CocktailSort(b, Max10000);
		puts("Array after coktail sort");
		print(Max10000, b);
		printf(" \n");
		printf("Size array for cocktail sort: %d \n", cocktailsort10000.size);
		printf("Count after coktail sort: %d \n", cocktailsort10000.count); 
		printf("coktail sort выполнялся %f секунд\n", cocktailsort10000.time);
		getch();

		/*FILE *in10000;
		in10000 = fopen("data.txt", "r");
		if (in10000 == NULL)
		{
			puts("File not found");
			getch();
		}
		fscanf(in10000, "%i", &N);
		for (i = 0; i < N; i++)
		{
			fscanf(in10000, "%i", &a[i]);
		}
		fclose(in10000);*/

		BuildAr(b, N);

		puts("Array before bubles sort");
		print(Max10000, b);
		getch();

		Par bublessort10000 = BublesSort(b, Max10000);
		puts("Array after bubles sort");
		print(Max10000, b);
		printf(" \n");
		printf("Size array for bubles sort: %d \n", bublessort10000.size);
		printf("Count after simple buble sort: %d \n", bublessort10000.count); // Выводим счётчик на экран
		printf("Bubles sort выполнялся %f секунд\n", bublessort10000.time);
		getch();
		free(b);

		
		int *c;
		c = (int*)malloc(Max10000 * sizeof(int));
		N = Max1000000;
		BuildAr(c, N);

		


		puts("Array before coktail sort");
		print(Max1000000, c);
		getch();
		Par cocktailsort1000000 = CocktailSort(c, Max1000000);
		puts("Array after coktail sort");
		print(Max1000000, c);
		printf(" \n");
		printf("Size array for cocktail sort: %d \n", cocktailsort1000000.size);
		printf("Count after coktail sort: %d \n", cocktailsort1000000.count); // Выводим счётчик на экран
		printf("coktail sort выполнялся %f секунд\n", cocktailsort1000000.time);
		getch();

		BuildAr(c, N);

		Par bublessort1000000 = BublesSort(c, Max1000000);
		puts("Array after bubles sort");
		print(Max1000000, c);
		printf(" \n");
		printf("Size array for bubles sort: %d \n", bublessort1000000.size);
		printf("Count after simple buble sort: %d \n", bublessort1000000.count); // Выводим счётчик на экран
		printf("Bubles sort выполнялся %f секунд\n", bublessort1000000.time);
		getch();
		free(c);

		printf("                 Size array  Count Swap Time \n");
		printf("=============================================\n");
		printf("Cocktail sort: %7d  %7d %7f \n", cocktailsort100.size, cocktailsort100.count, cocktailsort100.time);
		printf("Bubles sort:   %7d  %7d %7f \n", bublessort100.size, bublessort100.count, bublessort100.time);
		printf("Cocktail sort: %7d  %7d %7f \n", cocktailsort10000.size, cocktailsort10000.count, cocktailsort10000.time);
		printf("Bubles sort:   %7d  %7d %7f \n", bublessort10000.size, bublessort10000.count, bublessort10000.time);
		printf("Cocktail sort: %7d  %7d %7f \n", cocktailsort1000000.size, cocktailsort1000000.count, cocktailsort1000000.time);
		printf("Bubles sort:     %7d  %7d %7f \n", bublessort1000000.size, bublessort1000000.count, bublessort1000000.time);

		getch();
		return 0;
	}