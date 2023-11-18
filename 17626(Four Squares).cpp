#include<iostream>
#include<climits>

using namespace std;

int dp[50005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	dp[0] = 0;

	for (int i = 1; i <= 50000; i++) dp[i] = INT_MAX;

	for (int i = 1; i <= 50000; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}

	int n;
	cin >> n;
	cout << dp[n] << '\n';
}