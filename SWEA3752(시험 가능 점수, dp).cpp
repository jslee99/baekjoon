#include<iostream>

using namespace std;

int T, n;
int a[105];
bool dp[105][10005];
int ans;

void initDp() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			dp[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		initDp();

		for (int i = 1; i <= n; i++) cin >> a[i];

		dp[1][0] = true, dp[1][a[1]] = true;

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 10000; j++) {
				if (dp[i - 1][j] == true) {
					dp[i][j] = true;
					dp[i][j + a[i]] = true;
				}
			}
		}

		ans = 0;
		for (int j = 0; j <= 10000; j++) {
			if (dp[n][j] == true) ans++;
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}