#include<iostream>
#include<vector>

using namespace std;

vector<int> m1[105];
vector<int> m2[105];
pair<int, int> r[105];
int n, m;
int ans = 0;

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
		bool visit[105] = { false, };
		dfs(m1 ,i, visit);
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (visit[j]) cnt++;
		r[i].first = cnt - 1;
	}

	for (int i = 1; i <= n; i++) {
		bool visit[105] = { false, };
		dfs(m2, i, visit);
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (visit[j]) cnt++;
		r[i].second = cnt - 1;
	}


	int mid = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		if (r[i].first < mid && r[i].second < mid) ans++;
	}

	cout << n - ans << '\n';

	return 0;
}