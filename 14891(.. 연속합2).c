#include<stdio.h>

int num[100000];
int n;
int dp[100000][2];
int res;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	dp[0][0] = num[0];
	dp[0][1] = 0;
	for (int i = 1; i < n; i++) {
		if (dp[i - 1][0] > 0)
			dp[i][0] = dp[i - 1][0] + num[i];
		else
			dp[i][0] = num[i];

		if (dp[i - 1][1] + num[i] > dp[i - 1][0])
			dp[i][1] = dp[i - 1][1] + num[i];
		else
			dp[i][1] = dp[i - 1][0];
	}
	res = dp[0][0];
	for (int i = 1; i < n; i++) {
		if (res < dp[i][0])
			res = dp[i][0];
		else if (res < dp[i][1])
			res = dp[i][1];
	}
	printf("%d", res);
}


