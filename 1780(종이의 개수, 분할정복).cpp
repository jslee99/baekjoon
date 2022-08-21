#include<iostream>

int N;
int map[2187][2187];
int ans[3] = {0, 0, 0};

using namespace std;

void recur(int r, int c, int n) {
	int cri = map[r][c];

	bool is_one = true;
	for (int i = r; i < r + n; i++) {
		bool flag1 = false;
		for (int j = c; j < c + n; j++) {
			if (cri != map[i][j]) {
				flag1 = true;
				is_one = false;
				break;
			}
		}
		if (flag1) break;
	}

	if (is_one) {
		ans[cri + 1]++;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				recur(r + i * (n / 3), c + j * (n / 3), n / 3);
			}
		}
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];

	recur(0, 0, N);

	cout << ans[0] << endl << ans[1] << endl << ans[2] << endl;
}