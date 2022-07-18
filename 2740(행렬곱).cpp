#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int n, m, k;
	scanf("%d %d", &n, &m);
	int** arr1 = new int*[n];
	for (int i = 0; i < n; i++) {
		arr1[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	int** arr2 = new int* [m];
	for (int i = 0; i < m; i++) {
		arr2[i] = new int[k];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}
	int** arr3 = new int* [n];
	for (int i = 0; i < n; i++) {
		arr3[i] = new int[k];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			arr3[i][j] = 0;
		}
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < k; b++) {
			for (int c = 0; c < m; c++) {
				arr3[a][b] += arr1[a][c] * arr2[c][b];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
}