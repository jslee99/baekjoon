#include<stdio.h>

int dp[1001][10];
int n;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k] % 10007;
			}
			dp[i][j] = dp[i][j] % 10007;
		}
	}
	int res = 0;
	for (int i = 0; i < 10; i++) {
		res += dp[n][i] % 10007;
	}
	printf("%d", res % 10007);
}