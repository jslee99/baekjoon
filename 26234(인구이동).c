#include<stdio.h>
#include<stdlib.h>

int N, L, R;
int map[50][50];
int day = 0;
int visit[50][50];
int q[2500][2];
int tail = 0;
int total_p;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	visit[x][y] = 1;
	q[tail][0] = x, q[tail][1] = y;
	tail++;
	total_p += map[x][y];
	int new_x, new_y;
	for (int i = 0; i < 4; i++) {
		new_x = x + dx[i], new_y = y + dy[i];
		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && visit[new_x][new_y] == 0 && abs(map[x][y] - map[new_x][new_y]) >= L && abs(map[x][y] - map[new_x][new_y]) <= R) {
			dfs(new_x, new_y);
		}
	}
	return;
}

int main(void) {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	
	while (1) {
		int nation_num = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					total_p = 0;
					tail = 0;
					dfs(i, j);
					nation_num++;
					for (int k = 0; k < tail; k++) {
						map[q[k][0]][q[k][1]] = total_p / tail;
					}
				}
			}
		}
		if (nation_num == N * N)
			break;
		day++;
	}
	printf("%d\n", day);
}

