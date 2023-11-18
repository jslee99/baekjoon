#include<iostream>

using namespace std;

int T;
int map[100][100];
int R = 100, C = 100;

bool leftExists(int r, int c) {
	return c > 0 && map[r][c - 1] == 1;
}

bool rightExists(int r, int c) {
	return c < C - 1 && map[r][c + 1] == 1;
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	std::cout.tie(NULL);
	T = 10;

	for (int t = 1; t <= T; t++) {
		cin >> t;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
			}
		}
			
			 

		int r, c;
		for (int j = 0; j < C; j++) {
			if (map[R - 1][j] == 2) {
				r = R - 1, c = j;
			}
		}

		while (r > 0) {
			if (leftExists(r, c)) {
				while (leftExists(r, c)) {
					c--;
				}
				r--;
			}
			else if (rightExists(r, c)) {
				while (rightExists(r, c)) {
					c++;
				}
				r--;
			}
			else {
				r--;
			}
		}

		cout << '#' << t << ' ' << c << '\n';
	}
}