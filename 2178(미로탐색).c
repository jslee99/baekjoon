#include<stdio.h>
#include<stdlib.h>

int m, n;
int** a;
int q[10000][2];
int tail = 0, head = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int i, int j) {
	a[i][j] = 1;
	q[tail][0] = i, q[tail][1] = j;
	tail++;
	while (tail != head) {
		i = q[head][0];
		j = q[head][1];
		head++;
		for (int k = 0; k < 4; k++) {
			if (i + dx[k] >= 0 && i + dx[k] < m && j + dy[k] >= 0 && j + dy[k] < n && a[i + dx[k]][j + dy[k]] == -1) {
				a[i + dx[k]][j + dy[k]] = a[i][j] + 1;
				q[tail][0] = i + dx[k];
				q[tail][1] = j + dy[k];
				tail++;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &m, &n);
	a = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(sizeof(int) * n);
	}
	char temp[100];
	for (int i = 0; i < m; i++) {
		scanf("%s", temp);
		for (int j = 0; j < n; j++) {
			if (temp[j] == '1') {
				a[i][j] = -1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
	dfs(0, 0);
	printf("%d", a[m - 1][n - 1]);
}