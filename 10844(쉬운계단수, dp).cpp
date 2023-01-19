#include<iostream>
#define mod  1000000000

using namespace std;


int dp[101][10];
int N;
int ans = 0;

int main(void) {
	cin >> N;
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0;
			if (j - 1 < 0) {

			}
			else {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
			}

			if (j + 1 > 9) {

			}
			else {
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[N][i]) % mod;
	}

	cout << ans << endl;
}
