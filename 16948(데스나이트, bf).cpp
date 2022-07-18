#include<iostream>
#include<queue>

using namespace std;

int N;
int r1, c1;
int r2, c2;
queue<pair<int,int>> night_q;
int board[200][200];
int dr[6] = { -2, -2, 0, 0, 2, 2 };
int dc[6] = { -1, 1, -2, 2, -1, 1 };

bool is_in_and_is_not_checked(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N&& board[r][c] == -1;
}

int main(void) {
	cin >> N >> r1 >> c1 >> r2 >> c2;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = -1;
		}
	}

	board[r1][c1] = 0;
	night_q.push(make_pair(r1, c1));

	while (!night_q.empty()) {
		int r = night_q.front().first;
		int c = night_q.front().second;
		night_q.pop();
		for (int i = 0; i < 6; i++) {
			int new_r = r + dr[i];
			int new_c = c + dc[i];
			if (is_in_and_is_not_checked(new_r, new_c)) {
				board[new_r][new_c] = board[r][c] + 1;
				night_q.push(make_pair(new_r, new_c));
			}
		}
	}

	cout << board[r2][c2];
}
