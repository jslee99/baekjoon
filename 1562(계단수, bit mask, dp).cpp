#include<iostream>
#define MOD 1000000000;

using namespace std;
int N;
int full = 1023;
int dp[101][10][1024]; // 숫자길이, 끝에 있는 숫자 종류, check bit
// 100, 9, 111111110 의 뜻 : 길이가 100이고 끝자리가 9이면서 0을 제외한 모든 숫자를 사용한 계단수의 개수

int ret_ans(int len) {
	int ans = 0;
	for (int j = 0; j <= 9; j++) {
		ans = (ans + dp[len][j][full]) % MOD;
	}
	return ans;
}

int main(void) {
	cin >> N;

/*
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				dp[i][j][k] = -1;
			}
		}
	}*/

	for (int i = 1; i <= 9; i++) {
		dp[1][i][(1 << i)] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= full; k++) {
				if (dp[i][j][k] == 0) continue;

				if (j == 0) {
					dp[i + 1][j + 1][k | (1 << (j + 1))] = (dp[i + 1][j + 1][k | (1 << (j + 1))] + dp[i][j][k]) % MOD;
				}
				else if (j == 9) {
					dp[i + 1][j - 1][k | (1 << (j - 1))] = (dp[i + 1][j - 1][k | (1 << (j - 1))] + dp[i][j][k]) % MOD;
				}
				else {
					dp[i + 1][j + 1][k | (1 << (j + 1))] = (dp[i + 1][j + 1][k | (1 << (j + 1))] + dp[i][j][k]) % MOD;
					dp[i + 1][j - 1][k | (1 << (j - 1))] = (dp[i + 1][j - 1][k | (1 << (j - 1))] + dp[i][j][k]) % MOD;
				}
			}
		}
	}

	cout << ret_ans(N) << endl;
	/*
	long long test = 0;
	for (int i = 0; i <= 40; i++) {
		test += ret_ans(i);
	}*/
	//546184775
	return 0;
}