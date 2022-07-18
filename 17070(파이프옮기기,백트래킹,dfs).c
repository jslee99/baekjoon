#include<stdio.h>

int N;
int map[32][32];
long long cnt = 0;
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 1, 0 };

int dfs(int x_1, int y_1, int x_2, int y_2) {
	if (x_2 == N - 1 && y_2 == N - 1) {
		cnt++;
		return;
	}
	int new_x_2, new_y_2;
	if (x_1 == x_2) {//horizontal
		//move horizontal
		new_x_2 = x_2, new_y_2 = y_2 + 1;
		if (new_y_2 < N && map[new_x_2][new_y_2] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}
		//move diagonal
		new_x_2 = x_2 + 1, new_y_2 = y_2 + 1;
		if (new_x_2 < N && new_y_2 < N && map[new_x_2][new_y_2] == 0 && map[new_x_2 - 1][new_y_2] == 0 && map[new_x_2][new_y_2 - 1] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}
	}
	else if (y_1 == y_2) {//vetcial
		//move vertical
		new_x_2 = x_2 + 1, new_y_2 = y_2;
		if (new_x_2 < N && map[new_x_2][new_y_2] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}
		//move diagonal
		new_x_2 = x_2 + 1, new_y_2 = y_2 + 1;
		if (new_x_2 < N && new_y_2 < N && map[new_x_2][new_y_2] == 0 && map[new_x_2 - 1][new_y_2] == 0 && map[new_x_2][new_y_2 - 1] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}

	}
	else {//diagonal
		//move horizontal
		new_x_2 = x_2, new_y_2 = y_2 + 1;
		if (new_y_2 < N && map[new_x_2][new_y_2] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}
		//move vertical
		new_x_2 = x_2 + 1, new_y_2 = y_2;
		if (new_x_2 < N && map[new_x_2][new_y_2] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}
		//move diagonal
		new_x_2 = x_2 + 1, new_y_2 = y_2 + 1;
		if (new_x_2 < N && new_y_2 < N && map[new_x_2][new_y_2] == 0 && map[new_x_2 - 1][new_y_2] == 0 && map[new_x_2][new_y_2 - 1] == 0) {
			dfs(x_2, y_2, new_x_2, new_y_2);
		}
	}
}


int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0, 0, 1);
	printf("%lld\n", cnt);

	
	return 0;
}


