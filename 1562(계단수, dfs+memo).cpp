#include<iostream>
#define MOD 1000000000;

using namespace std;
int dp[101][10][1024]; 
// 90, 8, 111111110 �� �� : ���̰� 90�̰� ���� 8�̸鼭 0�� ������ ��� ���ڸ� ����� ���κ��� �����Ͽ�
//���̰� N(> 90)¥���� 0~9�� ��� ����� ��ܼ��� ���� �� �ִ� ����� ��(�� ������ N - 90�ڸ��� �� ä���� ���ǿ� �´� ��ܼ��� �����ϴ� ����� ��)

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