#include<iostream>

using namespace std;
int dp[31];
int n;

int main(void) {
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= 30; i++){
		if (i % 2 == 1) {
			dp[i] = 0;
		}
		else {
			dp[i] = dp[i - 2] * 3;
			for (int j = i - 4; j >= 0; j -= 2) {
				dp[i] += dp[j] * 2;
			}
		}
	}
	cout << dp[n] << endl;
}
