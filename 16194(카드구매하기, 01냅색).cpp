#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[1005];
int dp[1005][1005];

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[1][0] = 0;
	for (int j = 1; j <= n; j++) {
		dp[1][j] = a[1] * j;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= n; j++) {
			if (j - i < 0) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - i] + a[i]);
			}
		}
	}

	cout << dp[n][n];

	return 0;
}