#include<iostream>

using namespace std;

//1,000,000,007
long long dp[5005];
int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 5000; i += 2) {

		for (int j = 0; j <= i - 2; j += 2) {
			dp[i] += (dp[j] * dp[i - j - 2]);
			dp[i] %= 1000000007;
		}
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}


}