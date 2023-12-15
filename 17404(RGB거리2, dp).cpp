#include<iostream>

using namespace std;

int a[1005][3];
int dp[1005][3][3];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = 1000001;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i == j)
				continue;
			else
				dp[2][i][j] = a[1][i] + a[2][j];

	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = min(dp[i - 1][j][(k + 1) % 3], dp[i - 1][j][(k + 2) % 3]) + a[i][k];
			}
		}
	}

	int ans = 1000001;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i == j)
				continue;
			else
				ans = min(ans, dp[n][i][j]);

	cout << ans << '\n';
			

	return 0;
}