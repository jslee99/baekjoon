#include<iostream>
#include<algorithm>

using namespace std;

bool dp[35][40005];

int n;
int a[35];

int m;
int b[10];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];

	//sort(a + 1, a + n + 1, cmp);

	dp[1][0] = true;
	dp[1][a[1]] = true;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 40000; j++) {
			if (dp[i - 1][j] == true) {
				dp[i][j] = true;
				if (j - a[i] >= 0) {
					dp[i][j - a[i]] = true;
				}
				else {
					dp[i][abs(j - a[i])] = true;
				}
				if (j + a[i] <= 40000) {
					dp[i][j + a[i]] = true;
				}
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		if (dp[n][b[i]] == true) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}

	return 0;
}