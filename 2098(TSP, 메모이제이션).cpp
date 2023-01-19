#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
int dp[16][65536]; // 0 ~ N - 1, 0 ~ 2 ^ N - 1
int map[16][16];
int N;
int INF = 99999999;
int visit_mask[16];
//start_node : 0, dp[0][0000],

int dfs(int x, int visited_bit_mask) {
	if (dp[x][visited_bit_mask] == -1) {

		if (visited_bit_mask == (1 << N) - 1) {
			if (map[x][0] != 0) {
				dp[x][visited_bit_mask] = map[x][0];
			}
			else {
				dp[x][visited_bit_mask] = INF;
			}
		}
		else {
			dp[x][visited_bit_mask] = INF;
			for (int i = 0; i < N; i++) {
				if (map[x][i] != 0 && (visit_mask[i] & visited_bit_mask) == 0) {
					dp[x][visited_bit_mask] = min(dp[x][visited_bit_mask], dfs(i, visited_bit_mask | visit_mask[i]) + map[x][i]);
				}
			}
		}

	}
	else {
		
	}
	return dp[x][visited_bit_mask];
}


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < pow(2, N); j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		visit_mask[i] = (1 << i);
	}

	cout << dfs(0, (1 << 0)) << endl;
}