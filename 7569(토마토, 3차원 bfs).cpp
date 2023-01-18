#include<iostream>
#include<queue>

using namespace std;

int M, N, H;
int map[100][100][100]; // H M N
int dr[6] = { -1, 0, 1, 0, 0, 0 };
int dc[6] = { 0, -1, 0, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };
int res = -1;


bool is_in(int h, int r, int c) {
	return h >= 0 && h < H&& r >= 0 && r < M&& c >= 0 && c < N;
}

struct node {
	int h, r, c;
	int _time;
};

int main(void){
	cin >> N >> M >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[k][i][j];
			}
		}
	}

	queue<node> q;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[k][i][j] == 1) {
					node x;
					x.h = k, x.r = i, x.c = j;
					x._time = 0;
					q.push(x);
					map[k][i][j] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		node x;
		x = q.front();
		q.pop();
		if (map[x.h][x.r][x.c] == 1) continue;

		map[x.h][x.r][x.c] = 1;
		res = x._time;
		int new_h, new_r, new_c;
		for (int i = 0; i < 6; i++) {
			new_h = x.h + dh[i], new_r = x.r + dr[i], new_c = x.c + dc[i];
			if (is_in(new_h, new_r, new_c) && map[new_h][new_r][new_c] == 0) {
				node y;
				y.h = new_h, y.r = new_r, y.c = new_c;
				y._time = x._time + 1;
				q.push(y);
			}
		}
	}

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[k][i][j] == 0) {
					res = -1;
				}
			}
		}
	}
	
	cout << res << endl;
}
