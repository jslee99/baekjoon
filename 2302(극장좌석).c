#include<stdio.h>

int n;
int m;
int fix[40] = { 0, };
int dp[41];
int res = 1;

int main(void) 
{
	scanf("%d", &n);
	scanf("%d", &m);
	fix[0] = 0;
	fix[m + 1] = n + 1;
	for (int i = 1; i <= m; i++) 
	{
		scanf("%d", &fix[i]);
	}
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	for (int i = 0; i <= m; i++) {
		res *= dp[fix[i + 1] - fix[i] - 1];
	}
	
	printf("%d", res);

}