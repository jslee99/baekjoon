#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int map[130][130];
int visit[130][130];
int n, t;


int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int INF = 98765321;




bool isIn(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

void resetVisit() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visit[i][j] = INF;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	t = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;

		resetVisit();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		visit[0][0] = map[0][0];

		while (!q.empty()) {
			pair<int, int> x = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int r, c, w;
				r = x.first + dr[i], c = x.second + dc[i];
				if (!isIn(r, c)) continue;
				w = visit[x.first][x.second] + map[r][c];
				if (w < visit[r][c]) {
					visit[r][c] = w;
					q.push(make_pair(r, c));
				}
			}
		}

		cout << "Problem " << t++ << ": " << visit[n - 1][n - 1] << '\n';
	}
}