#include<iostream>
#include<vector>

using namespace std;

vector<int> m1[105];
vector<int> m2[105];
pair<int, int> r[105];
int n, m;
int ans = 0;
bool go[105][105];

void dfs(vector<int> g[], int x, bool visit[]) {
	if (visit[x]) return;
	visit[x] = true;

	for (int i = 0; i < g[x].size(); i++) {
		dfs(g, g[x][i], visit);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		m1[a].push_back(b);
		m2[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			go[i][j] = false;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m1[i].size(); j++) {
			go[i][m1[i][j]] = true;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (go[i][k] && go[k][j]) go[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (go[i][j]) cnt++;
		}
		r[i].first = cnt;
	}



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			go[i][j] = false;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m2[i].size(); j++) {
			go[i][m2[i][j]] = true;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (go[i][k] && go[k][j]) go[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (go[i][j]) cnt++;
		}
		r[i].second = cnt;
	}

	int cnt = 0;
	int mid = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		if (r[i].first < mid && mid > r[i].second) cnt++;
	}

	cout << n - cnt << '\n';

	return 0;
}