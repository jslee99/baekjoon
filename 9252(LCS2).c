#include<stdio.h>
#include<string.h>

int dp[1001][1001][2];//length   / 0:left 1:up  2:diagonal

char s1[1001];
char s2[1001];
int len1;
int len2;

void print_LCS(int len_1, int len_2) {
	if (len_1 == 0 || len_2 == 0) {
		return;
	}

	if (dp[len_1][len_2][1] == 2) {
		print_LCS(len_1 - 1, len_2 - 1);
		printf("%c", s1[len_1 - 1]);
	}
	else if (dp[len_1][len_2][1] == 1) {
		print_LCS(len_1 - 1, len_2);
	}
	else {
		print_LCS(len_1, len_2 - 1);
	}
}

int main(void) {
	scanf("%s", s1);
	scanf("%s", s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	dp[0][0][0] = 0;
	for (int i = 1; i <= len1; i++) {
		dp[i][0][0] = 0;
	}
	for (int i = 1; i <= len2; i++) {
		dp[0][i][0] = 0;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
				dp[i][j][1] = 2;
			}
			else {
				if (dp[i - 1][j][0] > dp[i][j - 1][0]) {
					dp[i][j][0] = dp[i - 1][j][0];
					dp[i][j][1] = 1;
				}
				else {
					dp[i][j][0] = dp[i][j - 1][0];
					dp[i][j][1] = 0;
				}
			}
		}
	}
	printf("%d\n", dp[len1][len2][0]);
	print_LCS(len1, len2);
}

