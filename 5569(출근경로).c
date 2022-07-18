#include<stdio.h>

int dp[100][100][4];
int n, m;

int main(void) {
	scanf("%d %d", &n, &m);// ans : m - 1, n - 1
	for (int i = 1; i < m; i++) 
		dp[i][0][0] = 1, dp[i][0][1] = 0, dp[i][0][2] = 0, dp[i][0][3] = 0;
	for (int j = 1; j < n; j++) 
		dp[0][j][3] = 1, dp[0][j][0] = 0, dp[0][j][1] = 0, dp[0][j][2] = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % 100000;
			dp[i][j][1] = dp[i - 1][j][3];
			dp[i][j][2] = dp[i][j - 1][0];
			dp[i][j][3] = (dp[i][j - 1][2] + dp[i][j - 1][3]) % 100000;
		}
	}
	printf("%d\n", (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1] + dp[m - 1][n - 1][2] + dp[m - 1][n - 1][3]) % 100000);

}



