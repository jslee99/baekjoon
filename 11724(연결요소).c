#include<stdio.h>
#include<stdlib.h>

void dfs(const int** a, int* visit, int i) {
	visit[i] = 1;
	int idx = 0;
	while (1) {
		if (a[i][idx] == -1) {
			break;
		}
		else {
			if (visit[a[i][idx]] == 0) {
				dfs(a, visit, a[i][idx]);
			}
		}
		idx++;
	}
}

int main(void) {
	int m, n;
	scanf("%d %d", &n, &m);

	int** a = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 1; i < n + 1; i++) {
		a[i] = (int*)malloc((n) * sizeof(int));
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = -1;
		}
	}
	int* visit = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 1; i < n + 1; i++) {
		visit[i] = 0;
	}

	while (m--) {
		int idx1, idx2;
		scanf("%d %d", &idx1, &idx2);
		for (int i = 0; i < n; i++) {
			if (a[idx1][i] == -1) {
				a[idx1][i] = idx2;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[idx2][i] == -1) {
				a[idx2][i] = idx1;
				break;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < n + 1; i++) {
		if (visit[i] == 0) {
			dfs(a, visit, i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	free(visit);
	for (int i = 1; i < n + 1; i++) {
		free(a[i]);
	}
	free(a);
}