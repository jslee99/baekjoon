#include<iostream>
#include<cstdio>

using namespace std;
int N, S, M;
int V[55];
bool dp[55][1005];

bool is_in(int x) {
	return x >= 0 && x <= M;
}

int main() {
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &V[i]);
	}
	
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 1005; j++) {
			dp[i][j] = false;
		}
	}

	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == true) {
				int a, b;
				a = j - V[i];
				b = j + V[i];
				if (is_in(a)) {
					dp[i][a] = true;
				}
				if (is_in(b)) {
					dp[i][b] = true;
				}
			}
		}
	}

	for (int j = M; j >= -1; j--) {
		if (dp[N][j] == true) {
			printf("%d\n", j);
			break;
		}
		if (j == -1) {
			printf("%d\n", -1);
		}
	}

	return 0;
}