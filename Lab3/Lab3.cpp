// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	for (int i = 0; i < SIZE; i++) {
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
	for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE - 1; j++) {
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
}
void ras(int x) {


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











	
	printf("\n\n");
	printf("Введите вершину, для расщепления \n");
	scanf("%d%d", &x1);
	ras(x1);
}
