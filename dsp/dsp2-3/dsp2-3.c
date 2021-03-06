// H28年度・DSP2-3・5J21
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define EPSILON 0.0001
#define N 3

double mat[N][N] = {
	{2.0, 1.0, 3.0},
	{1.0, 2.0, 3.0},
	{3.0, 3.0, 20.0}
};
double vec[N] = {1.0};
double lambda = 0.0;


void printMatrix() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("[%d][%d] = %lf ", i, j, mat[i][j]);
		}
		printf("\n");
	}
}

double calcApproximation(double vec_next[]) {
	int i, j;
	double lambda_next = 0;
	double tmp[N] = {0};
	double tmp_abs;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			tmp[i] += vec[j] * mat[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		lambda_next += tmp[i] * vec[i];
	}

	for (i = 0; i < N; i++) {
		tmp_abs += tmp[i] * tmp[i];
	}
	tmp_abs = sqrt(tmp_abs);
	for (i = 0; i < N; i++) {
		vec_next[i] = tmp[i] / tmp_abs;
	}

	return lambda_next;
}

double calcVariation(double vec_next[]) {
	int i;
	double variation = 0;

	for (i = 0; i < N; i++) {
		variation += (vec_next[i] - vec[i]) * (vec_next[i] - vec[i]);
	}
	variation = sqrt(variation);

	return variation;
}

void calcPower() {
	int i, j, k;
	double variation;
	double lambda_next;
	double vec_next[N];

	printf("H28年度・DSP2-3・5J21\n"
			"パワー法を用いて，固有値，固有ベクトルを計算します。\n\n");

	printf("Ann\n");
	printMatrix();

	for (k = 0; k < N; k++) {
		while (1) {
			variation = 0;
			lambda_next = 0;

			lambda_next = calcApproximation(vec_next);
			variation = calcVariation(vec_next);

			printf("%lf\n", variation);
			if (variation < EPSILON) break;

			lambda = lambda_next;
			for (i = 0; i < N; i++) {
				vec[i] = vec_next[i];
			}
		}

		printf("固有ベクトル\n");
		for (i = 0; i < N; i++) {
			printf("[%d] = %.6lf\n", i, vec[i]);
		}
		printf("固有値\n%.6lf\n", lambda);

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				mat[i][j] = mat[i][j] - lambda * vec[i] * vec[j];
			}
		}

		if ((k + 1) < N) {
			printf("\n残差行列\n");
			printMatrix();
		}
	}
}

int main(int argc, char const *argv[]) {
	calcPower();

	return 0;
}
