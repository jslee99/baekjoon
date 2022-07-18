#include<stdio.h>
#include<stdlib.h>

int** a;
int** dp;
int n;
int t;

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		a = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			a[i] = (int*)malloc(sizeof(int) * 2);
		}
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &a[i][j]);
			}
		}
		dp = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			dp[i] = (int*)malloc(sizeof(int) * 2);
		}
		dp[0][0] = a[0][0];
		dp[0][1] = a[0][1];
		if (n >= 2) {
			dp[1][0] = a[1][0] + a[0][1];
			dp[1][1] = a[1][1] + a[0][0];
		}
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (dp[i - 2][(j + 1) % 2] > dp[i - 1][(j + 1) % 2]) {
					dp[i][j] = dp[i - 2][(j + 1) % 2] + a[i][j];
				}
				else {
					dp[i][j] = dp[i - 1][(j + 1) % 2] + a[i][j];
				}
			}
		}
		if (dp[n - 1][0] > dp[n - 1][1]) {
			printf("%d\n", dp[n - 1][0]);
		}
		else {
			printf("%d\n", dp[n - 1][1]);
		}

		for (int i = 0; i < n; i++) {
			free(a[i]);
		}
		free(a);
		for (int i = 0; i < n; i++) {
			free(dp[i]);
		}
		free(dp);
	}
}