#include<iostream>
#include<vector>

using namespace std;

int m[105][105];
bool visit[105][105];
int n;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void resetVisit() {
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) visit[i][j] = false;
}

bool isIn(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

void dfs(int r, int c, int x) {
	visit[r][c] = true;

	for (int k = 0; k < 4; k++) {
		int newR = r + dr[k], newC = c + dc[k];
		if (isIn(newR, newC) && m[newR][newC] > x && !visit[newR][newC]) {
			dfs(newR, newC, x);
		} 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> m[i][j];

	int ans = 1;
	for (int r = 1; r <= 100; r++) {
		resetVisit();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && m[i][j] > r) {
					dfs(i, j, r);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}