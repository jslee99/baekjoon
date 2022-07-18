#include<stdio.h>
#include<stdlib.h>

int** a;
int n, m;
int q[1000000][2];
int tail, head = 0;
int dm[4] = { -1,0,1,0 };
int dn[4] = { 0,1,0,-1 };
int** visit;

void dfs() {
	int x, y;
	while (!(tail == head)) {
		x = q[head][0], y = q[head][1];
		head++;
		for (int i = 0; i < 4; i++) {
			if (x + dm[i] >= 0 && x + dm[i] < m && y + dn[i] >= 0 && y + dn[i] < n && visit[x + dm[i]][y + dn[i]] == -2) {
				visit[x + dm[i]][y + dn[i]] = 1 + visit[x][y];
				q[tail][0] = x + dm[i], q[tail][1] = y + dn[i];
				tail++;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	a = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	visit = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		visit[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == -1) {
				visit[i][j] = -1;
			}
			else {
				visit[i][j] = -2;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				visit[i][j] = 0;
				q[tail][0] = i, q[tail][1] = j;
				tail++;
			}
		}
	}
	//시작점이 여러개면 그거를 모두 queue에 넣고 시작한다.

	dfs();
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			/*
			if (visit[i][j] != -1) {
				if (visit[i][j] == -2) {
					res = -1;
					break;
				}
				else {
					if (visit[i][j] > res) {
						res = visit[i][j];
					}
				}
			}*/
			if (visit[i][j] == -2) {
				printf("%d\n", -1);
				return 0;
			}
			if (visit[i][j] > res) {
				res = visit[i][j];
			}
		}
		/*
		if (res == -1) {
			break;
		}*/
	}
	printf("%d\n", res);
}