#include<iostream>

using namespace std;

int m, n;
int a[260][260];
bool visit[260][260];
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int ans = 0;

bool isIn(int r, int c) {
	return r > 0 && r <= m && c > 0 && c <= n;
}

void dfs(int r, int c) {
	visit[r][c] = true;

	for (int k = 0; k < 8; k++) {
		int new_r = r + dr[k], new_c = c + dc[k];
		if (isIn(new_r, new_c) && !visit[new_r][new_c] && a[new_r][new_c] == 1)
			dfs(new_r, new_c);
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j] && a[i][j] == 1) {
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}