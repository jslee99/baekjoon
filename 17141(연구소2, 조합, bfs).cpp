#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int initMap[55][55];
int map[55][55];
vector<pair<int, int>> cand;
vector<pair<int, int>> virus;

int n, m;
int ans = 999999;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

// 00 15 43 60 66

bool isIn(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

void solve() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (initMap[i][j] == 0 || initMap[i][j] == 2) map[i][j] = -1;
		else map[i][j] = -2;
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		map[virus[i].first][virus[i].second] = 0;
		q.push({ virus[i].first, virus[i].second });
	}

	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int r, c;
			r = x.first + dr[k], c = x.second + dc[k];
			if (isIn(r, c) && map[r][c] == -1) {
				map[r][c] = map[x.first][x.second] + 1;
				q.push({ r, c });
			}
		}
	}

	int curAns = -1;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (map[i][j] == -1) {
			return;
		}
		else if (map[i][j] == -2) {
			//
		}
		else {
			curAns = max(curAns, map[i][j]);
		}
	}

	ans = min(ans, curAns);

	return;
}

void selectCand(int virusNum, int prevSelect) {
	if (virusNum == m) {
		solve();
		return;
	}

	for (int i = prevSelect + 1; i < cand.size(); i++) {
		virus.push_back(cand[i]);
		selectCand(virusNum + 1, i);
		virus.erase(virus.end() - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> initMap[i][j];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (initMap[i][j] == 2) cand.push_back({ i, j });

	selectCand(0, -1);

	if (ans == 999999) cout << -1 << '\n';
	else cout << ans << '\n';
}