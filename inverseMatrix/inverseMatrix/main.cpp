#include <stdio.h>

void mat_mul(double a[][4], double b[][4], double c[][4]) {
	int i, j, k;
	double val;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			val = 0;
			for (k = 0; k < 4; ++k)
				val = val + a[i][k] * b[k][j];
			c[i][j] = val;
		}
	}
}



int InvertMatrix(double m[][4], double invOut[][4]) {
	double inv[4][4], det;
	int i, j;
	
	inv[0][0] =
		m[1][1] * m[2][2] * m[3][3]
		- m[1][1] * m[2][3] * m[3][2]
		- m[2][1] * m[1][2] * m[3][3]
		+ m[2][1] * m[1][3] * m[3][2]
		+ m[3][1] * m[1][2] * m[2][3]
		- m[3][1] * m[1][3] * m[2][2];

	inv[0][1] =
		-m[0][1] * m[2][2] * m[3][3]
		+ m[0][1] * m[2][3] * m[3][2]
		+ m[2][1] * m[0][2] * m[3][3]
		- m[2][1] * m[0][3] * m[3][2]
		- m[3][1] * m[0][2] * m[2][3]
		+ m[3][1] * m[0][3] * m[2][2];

	inv[0][2] =
		m[0][1] * m[1][2] * m[3][3]
		- m[0][1] * m[1][3] * m[3][2]
		- m[1][1] * m[0][2] * m[3][3]
		+ m[1][1] * m[0][3] * m[3][2]
		+ m[3][1] * m[0][2] * m[1][3]
		- m[3][1] * m[0][3] * m[1][2];

	inv[0][3] =
		-m[0][1] * m[1][2] * m[2][3]
		+ m[0][1] * m[1][3] * m[2][2]
		+ m[1][1] * m[0][2] * m[2][3]
		- m[1][1] * m[0][3] * m[2][2]
		- m[2][1] * m[0][2] * m[1][3]
		+ m[2][1] * m[0][3] * m[1][2];

	inv[1][0] =
		-m[1][0] * m[2][2] * m[3][3]
		+ m[1][0] * m[2][3] * m[3][2]
		+ m[2][0] * m[1][2] * m[3][3]
		- m[2][0] * m[1][3] * m[3][2]
		- m[3][0] * m[1][2] * m[2][3]
		+ m[3][0] * m[1][3] * m[2][2];

	inv[1][1] =
		m[0][0] * m[2][2] * m[3][3]
		- m[0][0] * m[2][3] * m[3][2]
		- m[2][0] * m[0][2] * m[3][3]
		+ m[2][0] * m[0][3] * m[3][2]
		+ m[3][0] * m[0][2] * m[2][3]
		- m[3][0] * m[0][3] * m[2][2];

	inv[1][2] =
		-m[0][0] * m[1][2] * m[3][3]
		+ m[0][0] * m[1][3] * m[3][2]
		+ m[1][0] * m[0][2] * m[3][3]
		- m[1][0] * m[0][3] * m[3][2]
		- m[3][0] * m[0][2] * m[1][3]
		+ m[3][0] * m[0][3] * m[1][2];

	inv[1][3] =
		m[0][0] * m[1][2] * m[2][3]
		- m[0][0] * m[1][3] * m[2][2]
		- m[1][0] * m[0][2] * m[2][3]
		+ m[1][0] * m[0][3] * m[2][2]
		+ m[2][0] * m[0][2] * m[1][3]
		- m[2][0] * m[0][3] * m[1][2];

	inv[2][0] =
		m[1][0] * m[2][1] * m[3][3]
		- m[1][0] * m[2][3] * m[3][1]
		- m[2][0] * m[1][1] * m[3][3]
		+ m[2][0] * m[1][3] * m[3][1]
		+ m[3][0] * m[1][1] * m[2][3]
		- m[3][0] * m[1][3] * m[2][1];

	inv[2][1] =
		-m[0][0] * m[2][1] * m[3][3]
		+ m[0][0] * m[2][3] * m[3][1]
		+ m[2][0] * m[0][1] * m[3][3]
		- m[2][0] * m[0][3] * m[3][1]
		- m[3][0] * m[0][1] * m[2][3]
		+ m[3][0] * m[0][3] * m[2][1];

	inv[2][2] =
		m[0][0] * m[1][1] * m[3][3]
		- m[0][0] * m[1][3] * m[3][1]
		- m[1][0] * m[0][1] * m[3][3]
		+ m[1][0] * m[0][3] * m[3][1]
		+ m[3][0] * m[0][1] * m[1][3]
		- m[3][0] * m[0][3] * m[1][1];

	inv[2][3] =
		-m[0][0] * m[1][1] * m[2][3]
		+ m[0][0] * m[1][3] * m[2][1]
		+ m[1][0] * m[0][1] * m[2][3]
		- m[1][0] * m[0][3] * m[2][1]
		- m[2][0] * m[0][1] * m[1][3]
		+ m[2][0] * m[0][3] * m[1][1];

	inv[3][0] =
		-m[1][0] * m[2][1] * m[3][2]
		+ m[1][0] * m[2][2] * m[3][1]
		+ m[2][0] * m[1][1] * m[3][2]
		- m[2][0] * m[1][2] * m[3][1]
		- m[3][0] * m[1][1] * m[2][2]
		+ m[3][0] * m[1][2] * m[2][1];

	inv[3][1] =
		m[0][0] * m[2][1] * m[3][2]
		- m[0][0] * m[2][2] * m[3][1]
		- m[2][0] * m[0][1] * m[3][2]
		+ m[2][0] * m[0][2] * m[3][1]
		+ m[3][0] * m[0][1] * m[2][2]
		- m[3][0] * m[0][2] * m[2][1];

	inv[3][2] =
		-m[0][0] * m[1][1] * m[3][2]
		+ m[0][0] * m[1][2] * m[3][1]
		+ m[1][0] * m[0][1] * m[3][2]
		- m[1][0] * m[0][2] * m[3][1]
		- m[3][0] * m[0][1] * m[1][2]
		+ m[3][0] * m[0][2] * m[1][1];

	inv[3][3] =
		m[0][0] * m[1][1] * m[2][2]
		- m[0][0] * m[1][2] * m[2][1]
		- m[1][0] * m[0][1] * m[2][2]
		+ m[1][0] * m[0][2] * m[2][1]
		+ m[2][0] * m[0][1] * m[1][2]
		- m[2][0] * m[0][2] * m[1][1];


	det = m[0][0] * inv[0][0] + m[0][1] * inv[1][0] + m[0][2] * inv[2][0] + m[0][3] * inv[3][0];

	if (det == 0)
		return 0;

	det = 1.0 / det;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			invOut[i][j] = inv[i][j] * det;

	return 1;
}



int main() {

	int i, j, v;
	double s[4][4] = { {1,-2,3,5},{2,2,-1,0},{3,0,1,2},{1,0,2,0} };
	double r[4][4], t[4][4];

	printf("*****************************\n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%10.4f", s[i][j]);
		}
		printf("\n");
	}

	v = InvertMatrix(s, r);

	if (v == 0) printf("33333333333333333333333333");

	printf("*****************************\n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%10.4f", r[i][j]);
		}
		printf("\n");
	}

	mat_mul(s, r, t);

	printf("*****************************\n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%10.4f", t[i][j]);
		}
		printf("\n");
	}



	return 0;

}