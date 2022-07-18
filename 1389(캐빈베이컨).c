#include<stdio.h>

int n, m;
int f[101][101];
int x, y;
int visit[101];
int q[100];
int tail, head;
int sum;

void bfs() {
	int p, i;
	while (head != tail) {
		p = q[head];
		head++;
		i = 0;
		while (f[p][i] != -1) {
			if (visit[f[p][i]] == -1) {
				q[tail] = f[p][i];
				tail++;
				visit[f[p][i]] = visit[p] + 1;
				sum += visit[f[p][i]];
			}
			i++;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = -1;
		}
	}
	while (m--) {
		scanf("%d %d", &x, &y);
		for (int i = 0; i < n; i++) {
			if (f[x][i] == -1) {
				f[x][i] = y;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (f[y][i] == -1) {
				f[y][i] = x;
				break;
			}			
		}
	}
	int min = -1;
	int res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[j] = -1;
		}
		visit[i] = 0, tail = 0, head = 0, sum = 0;
		q[tail] = i;
		tail++;
		bfs();
		if (sum < min || min < 0) {
			min = sum;
			res = i;
		}
	}
	printf("%d", res);
}