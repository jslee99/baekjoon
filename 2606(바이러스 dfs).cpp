#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> map[105];
bool visit[105];

void dfs(int x) {
	visit[x] = true;
	vector<int>::iterator it;
	for (it = map[x].begin(); it != map[x].end(); it++) {
		if (!visit[*it]) dfs(*it);
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	dfs(1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i]) ans++;
	}
	
	cout << ans - 1 << '\n';
}