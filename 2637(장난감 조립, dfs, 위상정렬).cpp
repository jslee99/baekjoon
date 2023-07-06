#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> map[105];
int needNum[105][105];
vector<int> base;
bool visited[105];

int n, m;

void dfs(int nd) {
	visited[nd] = true;
	if (map[nd].size() == 0) {
		needNum[nd][nd] = 1;
		return;
	}

	for (int i = 0; i < map[nd].size(); i++) {
		if (!visited[map[nd][i].first]) dfs(map[nd][i].first);

		for (int j = 0; j < base.size(); j++) {
			needNum[nd][base[j]] += needNum[map[nd][i].first][base[j]] * map[nd][i].second;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= n; i++) {
		if (map[i].size() == 0) base.push_back(i);
	}

	dfs(n);

	for (int i = 0; i < base.size(); i++) {
		cout << base[i] << ' ' << needNum[n][base[i]] << '\n';
	}
}