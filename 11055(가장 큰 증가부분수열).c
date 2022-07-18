#include<stdio.h>
#include<stdlib.h>

int res = -1;

int main(void) {
	int n;
	scanf("%d", &n);
	int* s = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (dp[j] > max && s[i] > s[j]) {
				max = dp[j];
			}
		}
		dp[i] = max + s[i];
		if (dp[i] > res) {
			res = dp[i];
		}
	}
	printf("%d", res);
	free(dp);
	free(s);
}