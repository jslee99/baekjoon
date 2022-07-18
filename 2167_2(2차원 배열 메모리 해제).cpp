#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int m, n;
	scanf("%d %d", &n, &m); //rows : n  columns : m
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int c;
	int i, j, x, y;
	scanf("%d", &c);
	for (int k = 0; k < c; k++) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		int sum = 0;
		for (int r = i - 1; r < x; r++) {
			for (int co = j - 1; co < y; co++) {
				sum += arr[r][co];
			}
		}
		printf("%d\n", sum);
	}

	for (int r = 0; r < n; r++) {
		delete[] arr[r];
	}
	delete[] arr;

}