#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define EPSILON 0.0001
#define N 3

void printMatrix();
void calcPower();

int main(int argc, char const *argv[]) {
	int mat_col = N;
	double matrix[N * N] = {2, 1, 3, 1, 2, 3, 3, 3, 20};

	printf("Ann\n");
	printMatrix(matrix, mat_col);
	calcPower();

	return 0;
}

double *ensureDoubleArray(int data_size) {
	double *tmp;

	tmp = (double *)calloc(data_size, sizeof(double));

	return tmp;
}

void multMatrix(double *left_mat, int left_col, double *right_mat, int right_col) {
	int i, j, k;
	double *tmp;

	left_row = sizeof(left_mat)
	tmp = ensureDoubleArray()
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				tmp[i][j] += left_mat[i][k] * right_mat[k][j];
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			res[i][j] = tmp[i][j];
		}
	}
}

void transposeMatrix(double mat[][N], double res[][N]) {
	int i, j;
	double tmp[N][N] = {};

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			tmp[i][j] = mat[j][i];
		}


	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			res[i][j] = tmp[i][j];
		}
	}
}

void printMatrix() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("[%d][%d] = %lf ", i, j, matrix[i][j]);
		}
		printf("\n");
	}
}

void calcPower() {
	double unit_vector;

	while () {
		/* code */
	}
}
