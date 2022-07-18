#include<stdio.h>

int map[1000][1000];
int dp[1000][1000];
int m, n;
int max_line = 0;

int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		char buf[1001];
		scanf("%s", buf);
		for (int j = 0; j < n; j++) 
			map[i][j] = (int)(buf[j] - 48);
	}

	for (int i = 0; i < n; i++)
		if (map[0][i] == 1) {
			dp[0][i] = 1;
			max_line = 1;
		}
		else
			dp[0][i] = 0;

	for (int i = 1; i < m; i++)
		if (map[i][0] == 1) {
			dp[i][0] = 1;
			max_line = 1;
		}
		else
			dp[i][0] = 0;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == 0) {
				dp[i][j] = 0;
			}
			else {
				if (map[i - 1][j - 1] == 0 || map[i - 1][j] == 0 || map[i][j - 1] == 0){
					dp[i][j] = 1;
					if (dp[i][j] > max_line)
						max_line = dp[i][j];
				}
				else {
					int min = dp[i - 1][j - 1];
					if (min > dp[i - 1][j])
						min = dp[i - 1][j];
					if (min > dp[i][j - 1])
						min = dp[i][j - 1];
					dp[i][j] = min + 1;
					if (dp[i][j] > max_line)
						max_line = dp[i][j];
				}
			}
		}
	}
	printf("%d\n", max_line * max_line);

}