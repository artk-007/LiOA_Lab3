// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	const int N = 5;
	int G1[N][N], G2[N][N];
	int i, j, x , y;
	srand(time(NULL));
	for (i=0;i<N;i++)
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
			printf("%d ",G1[i][j]);
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
	printf("\n\n");
	printf("Введите 2 вершины для их отождествления \n");
	scanf("%d%d", &x, &y);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {

		}
	}

}
