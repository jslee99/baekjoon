#include<stdio.h>
#include<stdlib.h>

int n;
int** a;
int tail = 0;
int arr[500];
int dm[4] = { 1, 0, -1, 0 };
int dn[4] = { 0, -1, 0, 1 };

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2) {
		return -1;
	}
	else if (num1 > num2) {
		return 1;
	}
	else {
		return 0;
	}
}

int dfs(int i, int j) {
	a[i][j] = 2;
	int ret = 1;
	for (int k = 0; k < 4; k++) {
		if (i + dm[k] >= 0 && i + dm[k] < n && j + dn[k] >= 0 && j + dn[k] < n && a[i + dm[k]][j + dn[k]] == 1) {
			ret = ret + dfs(i + dm[k], j + dn[k]);
		}
	}
	return ret;
}


int main(void) {
	scanf("%d", &n);
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(sizeof(int) * n);
	}

	char temp[26];
	for (int i = 0; i < n; i++) {
		scanf("%s", &temp);
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				arr[tail] = dfs(i, j);
				tail++;
			}
		}
	}

	qsort(arr, tail, sizeof(int), compare);
	printf("%d\n", tail);
	for (int i = 0; i < tail; i++) {
		printf("%d\n", arr[i]);
	}
}