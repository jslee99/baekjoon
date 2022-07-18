#include<stdio.h>
#include<stdlib.h>

int** tri;
int** dp;
int n;

int main(void) {
	scanf("%d", &n);
	tri = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		tri[i] = (int*)malloc(sizeof(int) * (i + 1));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	dp = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (i + 1));
	}
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = tri[i][0] + dp[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		dp[i][i] = tri[i][i] + dp[i - 1][i - 1];
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[i - 1][j - 1] > dp[i - 1][j]) {
				dp[i][j] = tri[i][j] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = tri[i][j] + dp[i - 1][j];
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > max) {
			max = dp[n - 1][i];
		}
	}
	printf("%d\n", max);
}