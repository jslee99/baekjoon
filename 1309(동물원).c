#include<stdio.h>

int dp[100000][2];
int dp2[100000];
int n;

int main(void)
{
	scanf("%d", &n);
	dp[0][0] = 1, dp[0][1] = 1, dp2[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = (dp2[i - 1] + dp[i - 1][1]) % 9901;
		dp[i][1] = (dp2[i - 1] + dp[i - 1][0]) % 9901;
		dp2[i] = (dp[i - 1][0] + dp[i - 1][1] + dp2[i - 1]) % 9901;
	}
	printf("%d", (dp[n - 1][0] * 2 + dp2[n - 1]) % 9901);
}