#include<iostream>

using namespace std;

long long sum[1000005];
long long dp[1000005];

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; i * j <= 1000000; j++) {
			sum[i * j] += i;
		}
	}

	for (int i = 1; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + sum[i];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}