#include<stdio.h>

int dp[1001][1001];
int n, k;

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	printf("%d", dp[n][k]);
}