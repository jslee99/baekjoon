#include<stdio.h>

int N;
int map[32][32];
long long dp[32][32][3];// horizontal diagonla vetical


int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i < N; i++) {
		dp[0][i][0] = 1, dp[0][i][1] = 0, dp[0][i][2] = 0;
	}
	for (int i = 0; i < N; i++) {
		dp[i][0][0] = 0, dp[i][0][1] = 0, dp[i][0][2] = 0;
	}
	for (int i = 1; i < N; i++) {
		if (map[0][i] == 1) {
			for (int j = i; j < N; j++) {
				dp[0][j][0] = 0;
			}
			break;
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 1) {
				dp[i][j][0] = 0, dp[i][j][1] = 0, dp[i][j][2] = 0;
			}
			else {
				if (map[i - 1][j] == 1 || map[i][j - 1] == 1) {
					dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
					dp[i][j][1] = 0;
					dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
				}
				else {
					dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
					dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
					dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
				}
			}
		}
	}
	printf("%lld\n", dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2]);

	return 0;
}


