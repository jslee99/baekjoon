#include<stdio.h>
#include<stdlib.h>

int n;
int* price;
int* dp;

int main(void) {
	scanf("%d", &n);
	price = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &price[i]);
	}
	dp = (int*)malloc(sizeof(int) * (n + 1));
	dp[0] = 0;
	dp[1] = price[1];
	for (int i = 2; i <= n; i++) {
		int max = -1;
		for (int j = 1; j <= i; j++) {
			if (price[j] + dp[i - j] > max) {
				max = price[j] + dp[i - j];
			}
		}
		dp[i] = max;
	}
	printf("%d", dp[n]);

}