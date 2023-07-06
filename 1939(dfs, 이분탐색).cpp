#include<iostream>
#include<vector>

using namespace std;

int n, m;
int s, e;

vector<pair<int, int>> map[100005];
bool visit[100005];

void resetVisit() {
	for (int i = 1; i <= n; i++) {
		visit[i] = false;
	}
}

void dfs(int nd, const int w) {
	visit[nd] = true;

	for (int i = 0; i < map[nd].size(); i++) {
		int ch = map[nd][i].first;
		int upperW = map[nd][i].second;
		if (!visit[ch] && w <= upperW) dfs(ch, w);
	}
}

bool canGo(int w) {
	resetVisit();
	dfs(s, w);
	return visit[e];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}

	cin >> s >> e;

	int l = 1, r = 1000000001;// can cant

	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (canGo(m)) {
			l = m;
		}
		else {
			r = m;
		}
	}
		cout << l << '\n';


}