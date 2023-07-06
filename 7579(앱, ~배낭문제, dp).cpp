#include<iostream>

using namespace std;
int dp[101][10001];
int m[101];
int c[101];
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> m[i];
	for (int i = 1; i <= N; i++) cin >> c[i];

	for (int i = 1; i <= N; i++) {
		for(int j = 0; j <= 10000; j++){
			if (j - c[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], m[i] + dp[i - 1][j - c[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int j = 0; j <= 10000; j++) {
		if (dp[N][j] >= M) {
			cout << j << endl;
			break;
		}
	}
}