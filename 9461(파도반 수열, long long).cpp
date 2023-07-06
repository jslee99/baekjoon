#include<cstdio>

using namespace std;

long long dp[105];

int main() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}

/*
#include<algorithm>
#include<iostream>

char buf[100[;
scanf("%s", &buf);
*/