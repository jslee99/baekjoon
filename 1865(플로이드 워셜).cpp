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

				if (i == j) {//�ڱ��ڽſ��� ���ƿ��� ��Ȧ�� �������� �ʴ� ��쿡�� 0���� �ʱ�ȭ, ��Ȧ�� �����ϸ� �� ��Ȧ������ �ʱ�ȭ, �÷��̵� ���ȿ��� �ڱ� �ڽſ��� ���ƿ��� edge�� ������־�� �Ѵ�
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