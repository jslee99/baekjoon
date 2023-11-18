#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
int a[100005];
int dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[0] = 0;
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + a[i];
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}
}