#include<iostream>
#include<vector>

using namespace std;

int n, m, t;
int dp[25][10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		vector<int> c;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			c.push_back(a);
		}
		cin >> m;

		for (int j = 0; j <= m; j++) {
			if (j % c[0] == 0) dp[0][j] = 1;
			else dp[0][j] = 0;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				
				if (j - c[i] >= 0) {
					dp[i][j] += dp[i][j - c[i]];
				}
			}
		}

		cout << dp[n - 1][m] << '\n';
	}

}