#include<stdio.h>
#include<stdlib.h>

int t;
int l;
int st_m, st_n;
int ar_m, ar_n;
int** a;
int q[90000][2];
int tail, head;
int move[8][2] = {
	{1,2},
	{2,1},
	{2,-1},
	{1,-2},
	{-1,-2},
	{-2,-1},
	{-2,1},
	{-1,2}
};

void bfs(int i, int j) {
	while (1) {
		for (int p = 0; p < 8; p++) {
			if (i + move[p][0] >= 0 && i + move[p][0] <= l - 1 && j + move[p][1] >= 0 && j + move[p][1] <= l - 1 && a[i + move[p][0]][j + move[p][1]] == -1) {
				a[i + move[p][0]][j + move[p][1]] = a[i][j] + 1;
				if (i + move[p][0] == ar_m && j + move[p][1] == ar_n) {
					return;
				}
				q[tail][0] = i + move[p][0], q[tail][1] = j + move[p][1];
				tail++;
			}
		}
		i = q[head][0], j = q[head][1];
		head++;
	}
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &l);
		scanf("%d %d", &st_m, &st_n);
		scanf("%d %d", &ar_m, &ar_n);
		if (st_m == ar_m && st_n == ar_n) {
			printf("%d\n", 0);
			continue;
		}
		a = (int**)malloc(sizeof(int*) * l);
		for (int i = 0; i < l; i++) {
			a[i] = (int*)malloc(sizeof(int) * l);
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				a[i][j] = -1;
			}
		}
		a[st_m][st_n] = 0;
		q[0][0] = st_m, q[0][1] = st_n;
		tail = 1, head = 1;
		bfs(st_m, st_n);
		printf("%d\n", a[ar_m][ar_n]);
	
		for (int i = 0; i < l; i++) {
			free(a[i]);
		}
		free(a);
	}
}