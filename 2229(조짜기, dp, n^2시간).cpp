#include<iostream>

using namespace std;

int ma[1005][1005];
int mi[1005][1005];
int dp[1005][1005];
int a[1005];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
		ma[i][i] = a[i], mi[i][i] = a[i];

	for (int k = 2; k <= n; k++) {
		for (int i = 1; i + k - 1 <= n; i++) {
			ma[i][i + k - 1] = max(ma[i][i + k - 2], a[i + k - 1]);
			mi[i][i + k - 1] = min(mi[i][i + k - 2], a[i + k - 1]);
		}
	}
	
	for (int k = 2; k <= n; k++) {
		for (int i = 1; i + k - 1 <= n; i++) {
			dp[i][i + k - 1] = ma[i][i + k - 1] - mi[i][i + k - 1];
			for (int j = i + 1; j <= i + k - 1; j++) {
				dp[i][i + k - 1] = max(dp[i][i + k - 1], dp[i][j - 1] + dp[j][i + k - 1]);
			}
		}
	}
	

	cout << dp[1][n] << '\n';
}