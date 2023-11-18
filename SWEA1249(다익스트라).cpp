#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;
int map[105][105];
int visit[105][105];
int n, T;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void initMap() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) visit[i][j] = INT_MAX;
}

struct cmp {
	bool operator() (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second > b.second;
	}
};

priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;

bool isIn(int r, int c) {
	return r > 0 && r <= n && c > 0 && c <= n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		initMap();
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= n; j++) {
				map[i][j] = str[j - 1] - '0';
			}
		}

		pair<pair<int, int>, int> x = make_pair(make_pair(1, 1), 0);
		pq.push(x);
		while (!pq.empty()) {
			x = pq.top();
			pq.pop();
			if (visit[x.first.first][x.first.second] <= x.second) continue;
			visit[x.first.first][x.first.second] = x.second;

			for (int k = 0; k < 4; k++) {
				int new_r = x.first.first + dr[k], new_c = x.first.second + dc[k];
				if (isIn(new_r, new_c)) {
					pair<pair<int, int>, int> y = make_pair(make_pair(new_r, new_c), x.second + map[new_r][new_c]);
					pq.push(y);
				}
			}
		}

		cout << '#' << t << ' ' << visit[n][n] << '\n';
	}
}