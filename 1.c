#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>

void swap(float* xp, float* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(float arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}	
}

void main()
{
	float tabl[3][3] = { {0, 1 ,0}, {0,0,0.5},{1,0.5,0}};
	char imena[3][10] = { "Витя","Женя", "Олег" };
	char a;
	int n = sizeof(imena) / sizeof(imena[0]);
	while (1)
	{
		char c;
		setlocale(LC_ALL, "rus");
		printf("Меню:\n1. Распечатать таблицу;\n2. Участники;\n3. Вывести результаты турнира;\n4. Статистика участников;\n5. Выход.\n\n");
		printf("Ответ:");
		scanf("%c", &c);
		getchar();
		printf("\n");
		switch (c)
		{
		case '1'://вывести таблицу
		{
			for (int j = 0; j <= 3; j++)
			{
				printf("%5d|", j);
			}
			printf("\n");
			for (int i = 0; i < 3; i++)
			{
				printf("%5s|", imena[i]);
				for (int j = 0; j < 3; j++)
				{
					if (i == j)
					{
						printf(" --- |");
						continue;
					}
					else printf("%5.1f|", tabl[i][j]);
				}
				printf("\n");
			}
			break;
		}
		case '2'://вывести имена участников
		{
			for (int i = 0; i < 3; i++)
			{
				printf("%d. %s\n", i+1, imena[i]);
			}
			break;
		}
		case '3'://показать результаты 
		{
			
			for (int j = 0; j <= 3; j++)
			{
				printf("%5d|", j);
			}
			printf("Сумма очков");
			printf("\n");
			float sum[3]={0, 0, 0};
			for (int i = 0; i < 3; i++)
			{
				printf("%5s|", imena[i]);
				for (int j = 0; j < 3; j++)
				{
					
					if (i == j)
					{
						printf(" --- |");
						continue;
					}
					else printf("%5.1f|", tabl[i][j]);
					sum[i] += tabl[i][j];
				}
				printf("%11.1f", sum[i]);
				printf("\n");
			}
			printf("\n\n");
			bubbleSort(sum, n); 
			for (int i = 0; i < n; i++)
			{
				printf("%d место - %2.1f очков\n", i+1, sum[i]);
			}
			break;
		}
		case '4'://статистика участников
		{
			for (int i = 0; i < 3; i++)
			{
				int win = 0, lose=0, draw=0;
				for (int j = 0; j < 3; j++)
				{
					if (i == j) continue;
					else
					{
						if (tabl[i][j] == 1) win += 1;
						if (tabl[i][j] == 0) lose += 1;
						if (tabl[i][j]==0.5) draw += 1;
					}
				}
				printf("%s - %d побед, %d поражений, %d ничьих\n", imena[i], win, lose, draw);
			}
			break;
		}
		case '5'://выйти
			break;
		default: break;
		}
		if (c == '5') break;
		printf("\nПродолжить? Да - 1, нет - любой другой символ\nОтвет:");
		scanf("%c", &a);
		getchar();
		if (a != '1') break;
		printf("\n");
	}
	printf("Конец программы.");
}