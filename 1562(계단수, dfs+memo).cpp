#include<iostream>
#define MOD 1000000000;

using namespace std;
int dp[101][10][1024]; 
// 90, 8, 111111110 의 뜻 : 길이가 90이고 끝이 8이면서 0을 제외한 모든 숫자를 사용한 경우로부터 시작하여
//길이가 N(> 90)짜리인 0~9를 모두 사용한 계단수를 만들 수 있는 경우의 수(즉 나머지 N - 90자리를 다 채워서 조건에 맞는 계단수를 생성하는 경우의 수)

int N;
int full = 1023;
int ans = 0;

int dfs(int depth, int selected_num, int check_bit) {
	if (dp[depth][selected_num][check_bit] != -1) {
		return dp[depth][selected_num][check_bit];
	}	

	if (depth == N) {
		if (check_bit == full) {
			dp[depth][selected_num][check_bit] = 1;
			return dp[depth][selected_num][check_bit];
		}
		else {
			dp[depth][selected_num][check_bit] = 0;
			return dp[depth][selected_num][check_bit];
		}
	}

	int res = 0;
	if (selected_num - 1 >= 0) {
		res = (res + dfs(depth + 1, selected_num - 1, check_bit | (1 << (selected_num - 1)))) % MOD;
	}
	if (selected_num + 1 < 10) {
		res = (res + dfs(depth + 1, selected_num + 1, check_bit | (1 << (selected_num + 1)))) % MOD;
	}
	dp[depth][selected_num][check_bit] = res;
	return dp[depth][selected_num][check_bit];
}

int main() {
	cin >> N;

	for (int i = 0; i < 101; i++) for (int j = 0; j < 10; j++) for (int k = 0; k <= full; k++) dp[i][j][k] = -1;


	for (int i = 1; i <= 9; i++) {
		ans = (ans + dfs(1, i, (1 << i))) % MOD;
	}

	cout << ans << endl;

	return 0;
}