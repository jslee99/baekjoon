#include<iostream>

using namespace std;
int c, n;
int a[25][2];// qºñ¿ë, °í°´ ¼ö
int dp[25][1105];

int INF = 99999999;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}

	for (int i = 1; i <= 1100; i++) {
		if (i % a[1][1] == 0) {
			dp[1][i] = (i / a[1][1]) * a[1][0];
		}
		else {
			dp[1][i] = INF;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 1100; j++) {
			if (j - a[i][1] < 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = min(dp[i][j - a[i][1]] + a[i][0], dp[i - 1][j]);
			}
		}
	}

	int ans = INF;
	for (int i = c; i <= 1100; i++) {
		ans = min(ans, dp[n][i]);
	}


	cout << ans << '\n';

	return 0;
}