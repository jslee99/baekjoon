#include<iostream>
#define MOD 1000000000;

using namespace std;
int dp[101][10]; // 길이가 i이고 j로 시작하는(j는 0 가능) 계단수

int N;
int full = 1023;
int ans = 0;

void dfs(int depth, int selected_num, int check_bit) {
	if (check_bit == full) {
		if (depth == N) {
			ans = (ans + 1) % MOD;
		}
		else {
			if (selected_num == 0) {
				ans = (ans + dp[N - depth][selected_num + 1]) % MOD;
			}
			else if (selected_num == 9) {
				ans = (ans + dp[N - depth][selected_num - 1]) % MOD;
			}
			else {
				ans = (ans + dp[N - depth][selected_num + 1]) % MOD;
				ans = (ans + dp[N - depth][selected_num - 1]) % MOD;
			}
		}
		return;
	}

	if (depth == N) return;

	if (selected_num == 0) {
		dfs(depth + 1, selected_num + 1, check_bit | (1 << selected_num + 1));
	}
	else if (selected_num == 9) {
		dfs(depth + 1, selected_num - 1, check_bit | (1 << selected_num - 1));
	}
	else {
		dfs(depth + 1, selected_num + 1, check_bit | (1 << selected_num + 1));
		dfs(depth + 1, selected_num - 1, check_bit | (1 << selected_num - 1));
	}
}

int main() {
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	for (int i = 1; i <= 9; i++) {
		dfs(1, i, (1 << i));
	}

	cout << ans << endl;


	return 0;
}