#include<stdio.h>
#include<stdlib.h>

void reset(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}

void dfs(int** a, int x, int y, int m, int n) {
	a[x][y]++;
	if (x - 1 >= 0 && a[x - 1][y] == 1) {
		dfs(a, x - 1, y, m, n);
	}
	if (y + 1 <= n - 1 && a[x][y + 1] == 1) {
		dfs(a, x, y + 1, m, n);
	}
	if (x + 1 <= m - 1 && a[x + 1][y] == 1) {
		dfs(a, x + 1, y, m, n);
	}
	if (y - 1 >= 0 && a[x][y - 1] == 1) {
		dfs(a, x, y - 1, m, n);
	}
}

int main() {
	int t, m, n, k, x, y;
	int** a;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &m, &n, &k);
		a = malloc(m * sizeof(int*));
		for (int i = 0; i < m; i++) {
			a[i] = malloc(n * sizeof(int));
		}
		reset(a, m, n);
		while (k--) {
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					cnt++;
					dfs(a, i, j, m, n);
				}
			}
		}
		printf("%d\n", cnt);


		for (int i = 0; i < m; i++) {
			free(a[i]);
		}
		free(a);
	}
}