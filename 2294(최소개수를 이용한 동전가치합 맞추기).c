#include<stdio.h>

int n, k;
int val[100];
int dp[10001];

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= k; i++) {
		dp[i] = -1;
	}
	int min_val = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		if (min_val > val[i] || min_val == -1) {
			min_val = val[i];
		}
	}
	dp[0] = 0;
	for (int i = min_val; i <= k; i++) {
		int min = -1;
		for (int j = 0; j < n; j++) {
			if (val[j] > i || dp[i - val[j]] == -1) {
				continue;
			}

			if (min < 0 || min > dp[i - val[j]] + 1) {
				min = dp[i - val[j]] + 1;
			}
		}
		dp[i] = min;
	}
	printf("%d", dp[k]);
}