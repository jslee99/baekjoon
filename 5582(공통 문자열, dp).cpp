#include<iostream>

using namespace std;

int dp[4000][4000];
string str1, str2;
int max_length = 0;

int main(void) {
	cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 0; i < len1; i++) {
		//dp[i][0]
		if (str1[i] == str2[0]) {
			dp[i][0] = 1;
			max_length = 1;
		}
		else {
			dp[i][0] = 0;
		}
	}

	for (int i = 0; i < len2; i++) {
		if (str2[i] == str1[0]) {
			dp[0][i] = 1;
			max_length = 1;
		}
		else {
			dp[0][i] = 0;
		}
	}

	for (int i = 1; i < len1; i++) {
		for (int j = 1; j < len2; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > max_length)
					max_length = dp[i][j];
			}
		}
	}

	cout << max_length << endl;

}
