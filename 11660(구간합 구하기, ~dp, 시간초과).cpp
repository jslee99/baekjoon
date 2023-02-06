#include<iostream>

using namespace std;

int map[1024][1024];
int dp[1024][1024];
int N;
int M;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = map[0][0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i - 1][0] + map[i][0];
	}

	for (int j = 1; j < N; j++) {
		dp[0][j] = dp[0][j - 1] + map[0][j];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}

	while (M--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		int res;
		if (a == 0 && b == 0) {
			res = dp[c][d];
		}
		else if (a == 0) {
			res = dp[c][d] - dp[c][b - 1];
		}
		else if (b == 0) {
			res = dp[c][d] - dp[a - 1][d] ;
		}
		else {
			res =  dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1];
		}
		cout << res << '\n';
	}
}