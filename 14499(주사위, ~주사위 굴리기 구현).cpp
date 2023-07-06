#include<iostream>
#include<climits>

using namespace std;
int N, M, K;
int r, c;
int map[20][20];
int dice[6];
int dr[5] = { INT_MAX, 0, 0, -1, 1 };
int dc[5] = { INT_MAX, 1, -1, 0, 0 };

void turn(int dir) {
	int n0 = dice[0], n1 = dice[1], n2 = dice[2], n3 = dice[3], n4 = dice[4], n5 = dice[5];
	switch (dir) {
	case 1:
		dice[2] = n0, dice[1] = n1, dice[5] = n2, dice[0] = n3, dice[4] = n4, dice[3] = n5;
		break;
	case 2:
		dice[3] = n0, dice[1] = n1, dice[0] = n2, dice[5] = n3, dice[4] =  n4, dice[2] = n5;
		break; 
	case 3:
		dice[1] = n0, dice[5] = n1, dice[2] = n2, dice[3] = n3, dice[0] = n4, dice[4] = n5;
		break;
	case 4:
		dice[4] = n0, dice[0] = n1, dice[2] = n2, dice[3] = n3, dice[5] = n4, dice[1] = n5;
		break;
	}
}

bool is_in(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> r >> c >> K;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];

	int dir, new_r, new_c;
	while (K--) {
		cin >> dir;
		new_r = r + dr[dir], new_c = c + dc[dir];
		if (!is_in(new_r, new_c)) continue;

		r = new_r, c = new_c;
		turn(dir);
		if (map[r][c] == 0) {
			map[r][c] = dice[5];
		}
		else {
			dice[5] = map[r][c];
			map[r][c] = 0;
		}

		cout << dice[0] << '\n';
	}

}