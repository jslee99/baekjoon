#include<iostream>

using namespace std;

int map[101][101];
int N, M;

int main(void) {

	cin >> N >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = -1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][k] == 1 && map[k][j] == 1) map[i][j] = 1;
				if (map[i][k] == -1 && map[k][j] == -1) map[i][j] = -1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) cnt++;
		}
		cout << cnt - 1 << endl;
	}

	return 0;
}