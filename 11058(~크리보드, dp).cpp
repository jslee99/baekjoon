#include<iostream>
#include<cmath>

long long dp[105];

using namespace std;

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		for (int j = i - 3; j >= 1; j--) {
			dp[i] = max(dp[i], dp[j] * (i - j - 1));
		}
	}

	cout << dp[n] << endl;
	return 0;
}