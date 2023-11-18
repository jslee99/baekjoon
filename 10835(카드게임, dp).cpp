#include<iostream>

using namespace std;
int a[2005];
int b[2005];
int dp[2005][2005];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = n; i >= 1; i--) cin >> a[i];
	for (int i = n; i >= 1; i--) cin >> b[i];

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] <= b[j]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1] + b[j]));
			}
		}
	}

	cout << dp[n][n] << '\n';
}