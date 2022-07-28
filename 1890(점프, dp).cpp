#include<iostream>
#include<cmath>

using namespace std;
int map[100][100];
long long dp[100][100];
int N;

int main(void){
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0)
				break;
			if (j + map[i][j] < N) {
				dp[i][j + map[i][j]] += dp[i][j];
			}
			if (i + map[i][j] < N) {
				dp[i + map[i][j]][j] += dp[i][j];
			}
		}
	}

	cout << dp[N - 1][N - 1] << endl;
}