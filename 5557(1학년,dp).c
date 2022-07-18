#include<stdio.h>

int num[100];
long long dp[100][21];
int N;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < 21; j++)
			dp[i][j] = 0;
	
	dp[0][num[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 21; j++) {
			//-num[i]
			if (num[i] + j < 21) 
				dp[i][j] += dp[i - 1][j + num[i]];
			//+num[i]
			if (j - num[i] > -1)
				dp[i][j] += dp[i - 1][j - num[i]];
		}
	}
	printf("%lld\n", dp[N - 2][num[N - 1]]);
}

