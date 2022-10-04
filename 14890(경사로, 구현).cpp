#include<iostream>

using namespace std;


int N, L;
int map1[100][100];
int map2[100][100];
bool is_full[100];
int ans = 0;

void reset_is_full() {
	for (int i = 0; i < N; i++) is_full[i] = false;
}

void solve(int map[][100], int row) {
	reset_is_full();

	bool can_set = true;

	for (int i = 0; i < N - 1; i++) {
		if (map[row][i] != map[row][i + 1]) {
			if (map[row][i] - map[row][i + 1] == 1) {//내리막
				int cur_level = map[row][i + 1];

				if (!is_full[i + 1]) {
					is_full[i + 1] = true;
				}
				else {
					can_set = false;
					break;
				}

				for (int j = 2; j <= L; j++) {
					if (i + j < N && map[row][i + j] == cur_level && !is_full[i + j]) {
						is_full[i + j] = true;
					}
					else {
						can_set = false;
						break;
					}
				}

				if (!can_set) break;
				
			}
			else if (map[row][i] - map[row][i + 1] == -1) {//오르막
				int cur_level = map[row][i];
				
				if (!is_full[i]) {
					is_full[i] = true;
				}
				else {
					can_set = false;
					break;
				}

				for (int j = 1; j <= L - 1; j++) {
					if (i - j >= 0 && map[row][i - j] == cur_level && !is_full[i - j]) {
						is_full[i - j] = true;
					}
					else {
						can_set = false;
						break;
					}
				}

				if (!can_set) break;
				
			}
			else {
				can_set = false;
				break;
			}
		}
	}

	if (can_set) {
		ans++;
	}
}

int main(void) {
	cin >> N >> L;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map1[i][j];

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			map2[j][i] = map1[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		solve(map1, i);
		solve(map2, i);
	}

	cout << ans << endl;
}