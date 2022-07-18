#include<iostream>
using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	int* dp = new int[12];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int id;
	while (t--) {
		scanf("%d", &id);
		printf("%d\n", dp[id]);
	}

	delete[] dp;
}