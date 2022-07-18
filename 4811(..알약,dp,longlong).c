#include<stdio.h>

long long dp[31][31];
int n;

int main(void) {
	for (int i = 0; i < 31; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j < 31 - i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else {
				dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
			}
		}
	}
	scanf("%d", &n);
	while (n != 0) {
		printf("%lld\n", dp[n][0]);
		scanf("%d", &n);
	}
	
}