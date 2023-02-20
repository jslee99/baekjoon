#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<pair<int, int>> map[101];
int n, m, r;
int sector[101];
int dp[101][101];
int ans = INT_MIN;

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> sector[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INT_MAX;
		}
	}

	while (r--) {
		int a, b, l;
		cin >> a >> b >> l;
		dp[a][b] = l;
		dp[b][a] = l;
	}

	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int score = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m) {
				score += sector[j];
			}
		}
		ans = max(ans, score);
	}

	cout << ans << endl;
}