#include<iostream>

using namespace std;
int seq[1000];
int dp[1000];
int n;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i];

	int ans = 1;

	for (int i = 0; i < n; i++) {
		int j;
		int _max = 1;
		for (j = i - 1; j >= 0; j--) {
			if (seq[j] < seq[i]) {
				_max = max(_max, dp[j] + 1);
			}
		}

		dp[i] = _max;
		ans = max(ans, dp[i]);
	}


	cout << ans << endl;
}