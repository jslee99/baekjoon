#include<iostream>

using namespace std;

int map[205][205];
bool clean[205][205];
int r, c, n;
int t;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool isIn(int rr, int cc) {
	return rr >= 0 && rr < r && cc >= 0 && cc < c;
}

void reset() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			clean[i][j] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> n;

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			if (str[j] == '.')
				map[i][j] = 0;
			else
				map[i][j] = 2;
		}
	}

	t = 1;

	while (t < n) {
		reset();

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 3;
				}
				else {
					map[i][j]--;
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 0) {
					clean[i][j] = true;
					int new_r, new_c;
					for (int k = 0; k < 4; k++) {
						new_r = i + dr[k], new_c = j + dc[k];
						if (isIn(new_r, new_c))
							clean[new_r][new_c] = true;
					}
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (clean[i][j])
					map[i][j] = 0;
			}
		}
		t++;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 0)
				cout << '.';
			else
				cout << 'O';
		}
		cout << '\n';
	}
			

	return 0;
}