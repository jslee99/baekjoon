#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n] << '\n';
}