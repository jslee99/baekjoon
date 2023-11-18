#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
int n, q;
bool visit[5005];
vector<pair<int, int>> m[5005];
vector<int> usado[5005];

void initVisit() {
	for (int i = 1; i <= n; i++) visit[i] = false;
}

void dfs(const int s, int x, int u) {
	visit[x] = true;
	usado[s].push_back(u);
	for (vector<pair<int, int>>::iterator it = m[x].begin(); it != m[x].end(); it++) {
		if(!visit[(*it).first])
			dfs(s, (*it).first, min(u, (*it).second));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		m[a].push_back(make_pair(b, c));
		m[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i <= n; i++) {
		initVisit();
		dfs(i, i, INT_MAX);
	}

	for (int i = 1; i <= n; i++) {
		sort(usado[i].begin(), usado[i].end());
		usado[i].erase(--usado[i].end());
	}

	while (q--) {
		int k, v;
		cin >> k >> v;
		vector<int>::iterator it =  lower_bound(usado[v].begin(), usado[v].end(), k);
		int res = usado[v].end() - it;
		cout << res << '\n';
	}

	return 0; 
}