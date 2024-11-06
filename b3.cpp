#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 50

double cau1(int);
double cau2(int);
void cau3_in_ma_tran(int[][N], int);
void cau3(int[][N], int);
int cau3_so_sanh(int[][N], int m, int n, int p, int q);
bool cau3_dieukien(int[][N], int n);


double cau1(int n) {
	//code cau 1 tai day
	double sum = 0.0;
	double a = -1.0; //so hang cua tong s(n)
	double s = 0.0;
	for (double i = 1.0; i <= n; i++) {
		a *= -1.0;
		sum += i;
		s += a/sum;
	}
	return s;
}

double cau2(int n) {
	//code cau 2 tai day
	if (n == 1)
		return 1;
	if (n == 2)
		return 3.0 / 2.0;
	else
		return (1.0 + 1.0 / (cau2(n - 1)));
}
void cau3_in_ma_tran(int a[][N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int cau3_so_sanh(int a[][N], int m, int n, int p, int q) {
	if ((m + n > p + q && a[m][n] < a[p][q]) || (m + n < p + q && a[m][n] > a[p][q]))
		return 1; //can be swapped
	if (m + n == p + q) //same diagonal
	{
		if ((m + n) % 2 == 0) //even diagonal
		{
			if (m > p && a[m][n] > a[p][q]) //larger number below
				return 1;
			else if (m < p && a[m][n] < a[p][q]) //smaller number below
				return 1;
			else
				return 0; //can not
		}
		else //odd diagonal
		{
			if (m > p && a[m][n] < a[p][q])
				return 1;
			else if (m < p && a[m][n] > a[p][q])
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}

bool cau3_dieukien(int a[][N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (cau3_so_sanh(a, i, j, k, l))
						return true;
						break;
				}
			}
		}
	}
	return false;
}



void cau3(int a[][N], int n) {
	//code cau 3 tai day
	do {
		for (int s1 = 0; s1 <= 2 * n - 2; s1++)
		{
			for (int a1 = 0; a1 <= std::min(s1, n - 1); a1++)
			{
				if (s1 - a1 > n - 1)
					continue;
				else
					for (int s2 = 0; s2 <= 2 * n - 2; s2++)
					{
						for (int a2 = 0; a2 <= std::min(s2, n - 1); a2++)
						{
							if (s2 - a2 > n - 1)
								continue;
							else
							{
								if (cau3_so_sanh(a, a1, s1 - a1, a2, s2 - a2) == 1)
									std::swap(a[a1][s1 - a1], a[a2][s2 - a2]);
							}
						}

					}
			}

		}
	} while (cau3_dieukien(a, n));
	
	cau3_in_ma_tran(a, n);
}

int main() {
	int n1 = 0;
	printf_s("Nhap n cau 1: ");
	scanf_s("%d", &n1);
	double kq1 = cau1(n1);
	printf_s("Ket qua cau 1 la: %lf\n\n", kq1);

	int n2 = 0;
	printf_s("Nhap n cau 2: ");
	scanf_s("%d", &n2);
	double kq2 = cau2(n2);
	printf_s("Ket qua cau 2 la: %lf\n\n", kq2);

	int a[][N] = { {1, 11, 2, 4}, {3, 6, 10, 8}, {9, 15, 5, 12}, {13, 7, 14, 16} };
	int n3 = sizeof(a) / sizeof(a[0]);
	printf_s("Ma tran ban dau la\n\n");
	cau3_in_ma_tran(a, n3);
	printf_s("Ma tran sau khi sap xep la\n\n");
	cau3(a, n3);

	return 0;
}
