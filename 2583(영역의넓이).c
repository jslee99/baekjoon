#include<stdio.h>
#include<stdlib.h>

int a[100][100];
int m, n, k;
int square[100000];
int tail2 = 0;
int q[100000][2];
int head = 0, tail = 0;
int dm[4] = { 1, 0 ,-1, 0 };
int dn[4] = { 0, 1, 0, -1 };

int compare(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

void bfs() {
	int i, j, new_i, new_j;
	while (tail != head) {
		i = q[head][0];
		j = q[head][1];
		head++;
		for (int l = 0; l < 4; l++) {
			new_i = i + dm[l], new_j = j + dn[l];
			if (new_i < m && new_i >= 0 && new_j < n && new_j >= 0 && a[new_i][new_j] == 0) {
				a[new_i][new_j] = 1;
				q[tail][0] = new_i, q[tail][1] = new_j;
				tail++;
			}

		}
	}
}

int main(void) {
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
	while (k--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				a[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				a[i][j] = 1,q[tail][0] = i, q[tail][1] = j;
				tail++;			
				bfs();
				square[tail2] = tail;
				tail2++;
				head = 0, tail = 0;
			}
		}
	}
	qsort(square, tail2, sizeof(int), compare);
	printf("%d\n", tail2);
	for (int i = 0; i < tail2; i++) {
		printf("%d ", square[i]);
	}
}