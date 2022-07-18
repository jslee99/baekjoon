#include<stdio.h>

int dp[201][201];
int N, K;

int main(void) {
	scanf("%d %d", &N, &K);
	// k > 0
	for (int i = 0; i <= K; i++) {
		dp[0][i] = 1;
	}
	for (int i = 0; i <= N; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	printf("%d\n", dp[N][K]);
}


