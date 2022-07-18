#include<stdio.h>

int weight[100];
int value[100];
int dp[100][100001];
int N;
int K;

int main(void) {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}
	for (int i = 0; i < N; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i < weight[0]; i++) {
		dp[0][i] = 0;
	}
	for (int i = weight[0]; i <= K; i++) {
		dp[0][i] = value[0];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			if (weight[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j - weight[i]] + value[i] > dp[i - 1][j]) {
					dp[i][j] = dp[i - 1][j - weight[i]] + value[i];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}
	printf("%d\n", dp[N - 1][K]);

}


