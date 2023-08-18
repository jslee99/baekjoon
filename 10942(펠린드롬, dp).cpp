#include<iostream>

using namespace std;

int n;
int m;

int a[2005];
bool dp[2005][2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;

	for (int i = 1; i <= n; i++) dp[i][i] = true;

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1]) dp[i][i + 1] = true;
		else dp[i][i + 1] = false;
	}

	for (int k = 2; k <= n - 1; k++) {
		for (int i = 1; i + k <= n; i++) {
			if (dp[i + 1][i + k - 1] == true && a[i] == a[i + k]) dp[i][i + k] = true;
			else dp[i][i + k] = false;
		}
	}

	while (m--) {
		int s, e;
		cin >> s >> e;
		if (dp[s][e] == true)cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}