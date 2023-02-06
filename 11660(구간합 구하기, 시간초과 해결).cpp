#include<iostream>

using namespace std;

int dp[1025][1025];
int N;
int M;
int num;

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + num;
		}
	}

	while (M--) {
		int res;
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		
		res = dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1];

		printf("%d\n", res);
	}
}