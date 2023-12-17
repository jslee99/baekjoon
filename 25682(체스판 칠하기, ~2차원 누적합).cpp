#include<iostream>

using namespace std;
char a[2005][2005];
int dp[2005][2005][2]; // black, white
int n, m, k;

int main() {
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j - 1];
		}
	}

	if (a[1][1] == 'B') {
		dp[1][1][0] = 0;
		dp[1][1][1] = 1;
	}
	else {
		dp[1][1][0] = 1;
		dp[1][1][1] = 0;
	}

	for (int i = 2; i <= n; i++) {
		if (a[1][i] == 'B') {
			dp[1][i][0] = dp[1][i - 1][1];
			dp[1][i][1] = dp[1][i - 1][0] + 1;
		}
		else {
			dp[1][i][0] = dp[1][i - 1][1] + 1;
			dp[1][i][1] = dp[1][i - 1][0];
		}
	}

	for (int i = 2; i <= m; i++) {
		if (a[i][1] == 'B') {
			dp[i][1][0] = dp[i - 1][1][1];
			dp[i][1][1] = dp[i - 1][1][0] + 1;
		}
		else {
			dp[i][1][0] = dp[i - 1][1][1] + 1;
			dp[i][1][1] = dp[i - 1][1][0];
		}
	}

	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (a[i][j] == 'B') {
				dp[i][j][0] = dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][0];
				dp[i][j][1] = 1 + dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][1];
			}
			else {
				dp[i][j][0] = 1 + dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][0];
				dp[i][j][1] = dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][1];
			}
		}
	}

	int ans = 5000000;
	for (int i = k; i <= m; i++) {
		for (int j = k; j <= n; j++) {
			int b = dp[i][j][0] - dp[i - k][j][k % 2] - dp[i][j - k][k % 2] + dp[i - k][j - k][0];
			int w = dp[i][j][1] - dp[i - k][j][(k + 1) % 2] - dp[i][j - k][(k + 1) % 2] + dp[i - k][j - k][1];
			ans = min(ans, min(b, w));
		}
	}

	cout << ans << '\n';

	return 0;
}