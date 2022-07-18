#include<stdio.h>

char a[100][100];
int visit[100][100];
int N;
char buf[101];
int cnt1 = 0;
int cnt2 = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs1(int x, int y, char color) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i], new_y = y + dy[i];
		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && visit[new_x][new_y] == 0 && a[new_x][new_y] == color) {
			bfs1(new_x, new_y, a[new_x][new_y]);
		}
	}
}
void bfs2(int x, int y, char color) {
	visit[x][y] = 1;
	if (color == 'B') {
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && visit[new_x][new_y] == 0 && a[new_x][new_y] == 'B') {
				bfs2(new_x, new_y, a[new_x][new_y]);
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && visit[new_x][new_y] == 0 && a[new_x][new_y] != 'B') {
				bfs2(new_x, new_y, a[new_x][new_y]);
			}
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		for (int j = 0; j < N; j++) {
			a[i][j] = buf[j];
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				bfs1(i, j, a[i][j]);
				cnt1++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				bfs2(i, j, a[i][j]);
				cnt2++;
			}
		}
	}
	printf("%d %d", cnt1, cnt2);

}

