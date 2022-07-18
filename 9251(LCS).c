#include<stdio.h>
#include<string.h>

int dp[1001][1001];
char seq1[1000];
char seq2[1000];
int m, n;

int main(void) {
	scanf("%s", seq1);
	scanf("%s", seq2);
	m = strlen(seq1);
	n = strlen(seq2);
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= n; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (seq1[i - 1] == seq2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	printf("%d\n", dp[m][n]);
	return 0;
}