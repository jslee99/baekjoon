#include<iostream>
#include<queue>

using namespace std;

long long dp[1000001][2];
int N;

int main(void) {
	cin >> N;
	dp[0][0] = 1;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[3][0] = 22;
	dp[3][1] = 2;
	//dp[4][1] = 
	for (int i = 4; i <= N; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0] * 2) % 1000000007;
		dp[i][0] = (dp[i - 1][0] * 2 + dp[i - 2][0] * 3 + dp[i][1]) % 1000000007;
	}

	cout << dp[N][0] << endl;

}
