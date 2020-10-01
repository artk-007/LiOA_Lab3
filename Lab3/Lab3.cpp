// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
const int N = 5;
int G1[N][N], G2[N][N], G3[N][N];
void otj(int x1, int x2, int r) {
	int i, j;
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) 
			G3[i][j] = G1[i][j];
	
	x1--; x2--;
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}
	if (G1[x1][x2] == 1 && r==1)
		G3[x1][x1] == 1;
	else
		G3[x1][x1] == 0;
	for (i = 0; i < N; i++) {
		G3[i][x1] = G1[i][x1] || G1[i][x2];
	}
	for (j = 0; j < N; j++) {
		G3[x1][j] = G1[x1][j] || G1[x2][j];
	}

	printf("\n");
	printf("G1 otj \n");
	for (i = 0; i < N; i++) {
		if (i == x2)
			continue;;
		for (j = 0; j < N; j++) {
			if (j == x2)
				continue;;

			printf("%d ", G3[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int i, j, x1, x2, r ;
	srand(time(NULL));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {

			if (i == j) {
				G1[i][j] = 0;
				G2[i][j] = 0;
			}
			if (i < j) {
				G1[i][j] = rand() % 2;
				G1[j][i] = G1[i][j];
				G2[i][j] = rand() % 2;;
				G2[j][i] = G2[i][j];
			}
		}
	printf("G1 \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			G3[i][j] = G1[i][j];
			printf("%d ", G1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("G2 \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", G2[i][j]);
		}
		printf("\n");
	}
	//_________________Отождествление__________________
	printf("\n\n");
	printf("Введите 2 вершины для их отождествления \n");
	scanf("%d%d", &x1, &x2);
	if ((x1 > N) || (x2 > N) || (x1 < 1) || (x2 < 1))
		printf("\n ошибка Нет вершин(ы)\n");
	else {
		
		otj(x1, x2, 1);
	}
	//_______________________________________________________
	//_________________стягивание ребра__________________
	printf("\n\n");
	printf("Введите 2 вершины, смежные ребру, которое нужно стянуть \n");
	scanf("%d%d", &x1, &x2);
	if (G1[x1][x2] == 0)
		printf("\n ошибка Нет ребра\n");
	else
		if ((x1 > N) || (x2 > N) || (x1 < 1) || (x2 < 1))
			printf("\n ошибка Нет вершин(ы)\n");
		else {
			
			otj(x1, x2, 0);
		}
	//_______________________________________________________

}
