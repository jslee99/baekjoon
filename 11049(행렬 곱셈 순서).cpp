#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int N;
int mat[500][2];
int dp[500][500];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> mat[i][0] >> mat[i][1];

	for (int k = 1; k <= N - 1; k++) {
		for (int i = 0; i + k <= N - 1; i++) { // i ~ i + k¸¦ °áÁ¤
			dp[i][i + k] = INT_MAX;
			for (int j = i; j < i + k; j++) { // i ~ j, j + 1 ~ i + k
				dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + mat[i][0] * mat[j][1] * mat[i + k][1]);
			}
		}
	}

	cout << dp[0][N - 1] << endl;
}