﻿// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
#define SIZE 5
void rand_Zap(int k, int(&Matrix)[SIZE][SIZE]) {
	srand(time(NULL) * k);
	printf("G%d \n",k);
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if (i == j) {
				Matrix[i][j] = 0;
			}
			if (i < j) {
				Matrix[i][j] = rand() % 2;
				Matrix[j][i] = Matrix[i][j];
			}
		}
}
void print_G(int (&Matrix)[SIZE][SIZE] ){
	printf("   1 2 3 4 5\n\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d  ",i+1);
		for (int j = 0; j < SIZE; j++) {
			
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void copy(int(&Matrix1)[SIZE][SIZE], int(&Matrix2)[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			Matrix2[i][j] = Matrix1[i][j];
}
void otj(int (&constant)[SIZE][SIZE], int (&work)[SIZE][SIZE], int (&Matrix)[SIZE - 1][SIZE - 1]){
	int x1, x2;
	printf("Введите 2 вершины для их отождествления \n");
	scanf("%d%d", &x1, &x2);
	int	i, j, i1, j1;
	x1--; x2--;
	if ((x1 > SIZE - 1) || (x2 > SIZE - 1) || (x1 < 0) || (x2 < 0)) {
		printf("\n ошибка Нет вершин(ы)\n");
		return;
	}
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}
	copy(constant, work);
	for (i = 0; i < SIZE; i++) {
		work[i][x1] = constant[i][x1] || constant[i][x2];
	}
	for (j = 0; j < SIZE; j++) {
		work[x1][j] = constant[x1][j] || constant[x2][j];
	}
	for (i = 0, i1=x2+1; i < SIZE - 1; i++) {
		for (j = 0, j1 = x2; j < SIZE - 1; j++) {
			if (j >= x2)
				j1++;
			if (i < x2 && j < x2)
				Matrix[i][j] = work[i][j];
			if (i < x2 && j >= x2)
				Matrix[i][j] = work[i][j1];
			if (i >= x2 && j < x2)
				Matrix[i][j] = work[i1][j];
			if (i >= x2 && j >= x2)
				Matrix[i][j] = work[i1][j1];
		}
		if (i >= x2) i1++;
	}
	if (constant[x1][x2] == 1)
		Matrix[x1][x1] = 1;
	else
		Matrix[x1][x1] = 0;
	printf("Результат отождествления\n");
	for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE - 1; j++) {
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
}
void stig(int(&constant)[SIZE][SIZE], int(&work)[SIZE][SIZE], int(&Matrix)[SIZE - 1][SIZE - 1]) {
	int x1, x2;
	printf("Введите 2 вершины, смежные ребру, которое нужно стянуть \n");
	scanf("%d%d", &x1, &x2);
	int	i, j, i1, j1;
	x1--; x2--;
	if ((x1 > SIZE - 1) || (x2 > SIZE - 1) || (x1 < 0) || (x2 < 0)) {
		printf("\n ошибка Нет вершин(ы)\n");
		return;
	}
	else
		if (constant[x1][x2] == 0) {
			printf("\n ошибка Нет ребра\n");
			return;
		}
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}
	copy(constant, work);
	for (i = 0; i < SIZE; i++) {
		work[i][x1] = constant[i][x1] || constant[i][x2];
	}
	for (j = 0; j < SIZE; j++) {
		work[x1][j] = constant[x1][j] || constant[x2][j];
	}
	for (i = 0, i1 = x2 + 1; i < SIZE - 1; i++) {
		for (j = 0, j1 = x2; j < SIZE - 1; j++) {
			if (j >= x2)
				j1++;
			if (i < x2 && j < x2)
				Matrix[i][j] = work[i][j];
			if (i < x2 && j >= x2)
				Matrix[i][j] = work[i][j1];
			if (i >= x2 && j < x2)
				Matrix[i][j] = work[i1][j];
			if (i >= x2 && j >= x2)
				Matrix[i][j] = work[i1][j1];
		}
		if (i >= x2) i1++;
	}
	Matrix[x1][x1] = 0;
	printf("Результат стягивания\n");
	for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE - 1; j++) {
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
}
void ras(int (&constant)[SIZE][SIZE], int(&Matrix)[SIZE + 1][SIZE + 1]) {
	int x, i, j, i1;
	printf("Введите вершину для расщепления\n");
	scanf("%d", &x);
	x--;
	/*for (i = 0; i < SIZE + 1; i++) {
		for (j = 0; j < SIZE + 1; j++) {
			if (i < x && j < x)
				Matrix[i][j] = constant[i][j];
			if (i < x && j > x)
				Matrix[i][j] = constant[i][j-1];
			if (i > x && j < x)
				Matrix[i][j] = constant[i-1][j];
			if (i > x && j > x)
				Matrix[i][j] = constant[i-1][j-1];
		}
	}*/
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			Matrix[i][j] = constant[i][j];
		}
	}
	for (i = 0; i < SIZE + 1; i++) {
		for (j = 0; j < SIZE + 1; j++) {
			if (i == 5 || j == 5) {
				Matrix[5][j] = 0;
				Matrix[j][5] = 0;
			}
		}
	}
		for (j = 0; j < SIZE; j++) {
			if (Matrix[x][j] == 1)
				if (j % 2 == 0) {
					Matrix[5][j] = 1;
					Matrix[j][5] = 1;
					Matrix[x][j] = 0;
					Matrix[j][x] = 0;
				}
				
		}
		Matrix[x][5] = 1;
		Matrix[5][x] = 1;
		printf("Результат расщепления\n");
	printf("\n");
	for (i = 0; i < SIZE + 1; i++) {

		for (j = 0; j < SIZE + 1; j++) {
			printf("  %d ", Matrix[i][j]);
		}
		printf("\n");
	}
}
void obed(int(&Matrix1)[SIZE][SIZE], int(&Matrix2)[SIZE][SIZE]) {
	int res[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			res[i][j] = Matrix1[i][j] || Matrix2[i][j];
		}
	printf("Результат объединения G1 и G2\n");
	print_G(res);
}
void perseh(int(&Matrix1)[SIZE][SIZE], int(&Matrix2)[SIZE][SIZE]) {
	int res[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if (Matrix1[i][j]==1 && Matrix2[i][j]==1)
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	printf("Результат пересечения G1 и G2\n");
	print_G(res);
}
void kolc_sum(int(&Matrix1)[SIZE][SIZE], int(&Matrix2)[SIZE][SIZE]) {
	int res[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if ((Matrix1[i][j] == 1 && Matrix2[i][j] == 0) || (Matrix1[i][j] == 0 && Matrix2[i][j] == 1))
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	printf("Результат кольцевой суммы G1 и G2\n");
	print_G(res);
}
int main(){
	const int N = 5;
	int G1[N][N], G2[N][N], G3[N][N], G4[N - 1][N - 1], G5[N + 1][N + 1];
	setlocale(LC_ALL, "Rus");
	rand_Zap(1,G1);
	print_G(G1);
	rand_Zap(2,G2);
	print_G(G2);
	
	otj(G1, G3, G4);

	stig(G1, G3, G4);
	ras(G1, G5);
	obed(G1, G2);
	perseh(G1, G2);
	kolc_sum(G1, G2);
}
