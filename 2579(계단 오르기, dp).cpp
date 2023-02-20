#include<iostream>

using namespace std;

int score[300];
int dp[300][2];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> score[i];

	dp[0][0] = score[0];
	dp[0][1] = score[0];
	dp[1][0] = dp[0][1] + score[1];
	dp[1][1] = score[1];

	for (int i = 2; i < N; i++) {
		dp[i][0] = dp[i - 1][1] + score[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + score[i];
	}

	cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
}