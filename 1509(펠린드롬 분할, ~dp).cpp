#include<iostream>
#define LEN 2500

using namespace std;
bool P[LEN][LEN];
int dp[LEN];
string str;

int main() {
	cin >> str;
	for (int i = 0; i < (int)str.size(); i++) {
		P[i][i] = true;
	}

	for (int i = 0; i + 1 < (int)str.size(); i++) {
		if (str[i] == str[i + 1])
			P[i][i + 1] = true;
	}

	for (int k = 2; k <= (int)str.size() - 1; k++) {
		for (int i = 0; i + k < (int)str.size(); i++) {
			if (str[i] == str[i + k] && P[i + 1][i + k - 1] == true)
				P[i][i + k] = true;
		}
	}

	dp[0] = 1;

	for (int i = 1; i < (int)str.size(); i++) {
		if (P[0][i] == true) {
			dp[i] = 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
			for (int j = i - 2; j >= 0; j--) {
				if (P[j + 1][i] == true) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
	}

	cout << dp[(int)str.size() - 1] << endl;
}