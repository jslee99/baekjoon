#include<iostream>

using namespace std;

long long dp[15][70];
int t;
int n;

int main() {
	for (int i = 0; i < 10; i++) 
		dp[i][1] = 1;
	
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[j][i] += dp[k][i - 1];
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < 10; i++)
			ans += dp[i][n];

		cout << ans << '\n';
	}


	return 0;
}