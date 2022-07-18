#include<stdio.h>

int a[100][100];
int res[100][100];
int visit[100];
int N;

void dfs(i) {
	for (int j = 0; j < N; j++) {
		if (a[i][j] == 1 && visit[j] == 0) {
			visit[j] = 1;
			dfs(j);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
			res[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		visit[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		dfs(i);
		for (int j = 0; j < N; j++) {
			res[i][j] = visit[j];
			visit[j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

}
