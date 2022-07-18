#include<iostream>
using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	int** dp = new int*[41];
	for (int i = 0; i < 41; i++) {
		dp[i] = new int[2];
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	int id;
	while (t--) {
		scanf("%d", &id);
		printf("%d %d\n", dp[id][0], dp[id][1]);
	}

	for (int i = 0; i < 41; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}