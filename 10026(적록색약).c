#include<stdio.h>

int a[100][100];
int n;
char temp[101];
int visit[100][100];
int dm[4] = { -1, 0, 1, 0 };
int dn[4] = { 0, 1, 0, -1 };
int cnt1 = 0, cnt2 = 0;

void bfs1(int i, int j) {
	visit[i][j] = 1;
	int new_i, new_j;
	for (int k = 0; k < 4; k++) {
		new_i = i + dm[k], new_j = j + dn[k];
		if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visit[new_i][new_j] == -1 && a[i][j] == a[new_i][new_j])
			bfs1(new_i, new_j);
	}
}

void bfs2(int i, int j) {
	visit[i][j] = 1;
	int new_i, new_j;
	if (a[i][j] == 'B') {
		for (int k = 0; k < 4; k++) {
			new_i = i + dm[k], new_j = j + dn[k];
			if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visit[new_i][new_j] == -1 && a[new_i][new_j] == 'B')
				bfs2(new_i, new_j);
		}
	}
	else {
		for (int k = 0; k < 4; k++) {
			new_i = i + dm[k], new_j = j + dn[k];
			if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visit[new_i][new_j] == -1 && a[new_i][new_j] != 'B')
				bfs2(new_i, new_j);
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &temp);
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = -1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1) {
				bfs1(i, j);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1) {
				bfs2(i, j);
				cnt2++;
			}
		}
	}
	printf("%d %d", cnt1, cnt2);
}