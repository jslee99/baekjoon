#include<iostream>
#include<limits>

using namespace std;

long long INF = 1000000000;

long long map[501][501];
long long dp[501][501];

int TC, N, M, W;

int main(void) {

	cin >> TC;
	while (TC--) {

		cin >> N >> M >> W;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = INF;
			}
		}

		while (M--) {
			long long S, E, T;
			cin >> S >> E >> T;
			map[S][E] = min(map[S][E], T);
			map[E][S] = min(map[E][S], T);
		}

		while (W--) {
			int S, E, T;
			cin >> S >> E >> T;
			map[S][E] = -T;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] = map[i][j];

				if (i == j) {//자기자신에게 돌아오는 웜홀이 존재하지 않는 경우에는 0으로 초기화, 웜홀이 존재하면 그 웜홀값으로 초기화, 플로이드 워셜에서 자기 자신에게 돌아오는 edge를 고려해주어야 한다
					if (map[i][j] > 0) {
						dp[i][j] = 0;
					}
				}
			}
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}


		bool flag = false;
		for (int i = 1; i <= N; i++) {
			if (dp[i][i] < 0) {
				flag = true;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}