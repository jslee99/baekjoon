#include<stdio.h>
#include<stdlib.h>

int n;
int* item;
int* dp;//including i
int* dp2;//excluding i

int main(void) {
	scanf("%d", &n);
	item = (int*)malloc(sizeof(int) * n);
	dp = (int*)malloc(sizeof(int) * n);
	dp2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &item[i]);
	}
	dp[0] = item[0];
	dp[1] = dp[0] + item[1];
	dp2[0] = 0;
	dp2[1] = item[0];
	for (int i = 2; i < n; i++) {
		if (dp[i - 2] > item[i - 1] + dp2[i - 2]) {
			dp[i] = item[i] + dp[i - 2];
		}
		else {
			dp[i] = item[i] + item[i - 1] + dp2[i - 2];
		}

		if (dp[i - 2] > dp[i - 1]) {
			dp2[i] = dp[i - 2];
		}
		else {
			dp2[i] = dp[i - 1];
		}
	}

	if (n == 1) {
		printf("%d", dp[0]);
	}
	else {
		if (dp[n - 2] > dp[n - 1]) {
			printf("%d", dp[n - 2]);
		}
		else {
			printf("%d", dp[n - 1]);
		}
	}
 }