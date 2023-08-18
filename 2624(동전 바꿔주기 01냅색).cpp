#include<iostream>
#include<algorithm>

using namespace std;

int t, k;
int a[105][2]; // ±Ý¾× °¡Áþ¼ö
int dp[105][10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i][0] >> a[i][1];
	}

	dp[1][0] = 1;
	for (int i = 1; i <= a[1][1] && a[1][0] * i <= 10000; i++) {
		dp[1][a[1][0] * i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 10000; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int m = 1; m <= a[i][1]; m++) {
				if (j - m * a[i][0] < 0) break;

				dp[i][j] += dp[i - 1][j - m * a[i][0]];
			}
		}
	}

	cout << dp[k][t];

	return 0;
}