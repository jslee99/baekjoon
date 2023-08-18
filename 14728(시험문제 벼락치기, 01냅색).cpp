#include<iostream>
#include<algorithm>

using namespace std;

int t, n;
int a[105][2];//시간 배점
int dp[105][10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}

	for (int i = a[1][0]; i <= 10000; i++) {
		dp[1][i] = a[1][1];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (j - a[i][0] < 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i][0]] + a[i][1]);
			}
		}
	}

	cout << dp[n][t] << '\n';

	return 0;
}