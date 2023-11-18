#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
int n, q;
bool visit[5005];
vector<pair<int, int>> m[5005];

void initVisit() {
	for (int i = 1; i <= n; i++) visit[i] = false;
}

void dfs(int x, int k) {
	visit[x] = true;
	for (vector<pair<int, int>>::iterator it = m[x].begin(); it != m[x].end(); it++) {
		if (!visit[(*it).first] && k <= (*it).second)
			dfs((*it).first, k);
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

	while (q--) {
		initVisit();
		int k, v;
		cin >> k >> v;
		dfs(v, k);
		int res = -1;
		for (int i = 1; i <= n; i++) if (visit[i]) res++;
		cout << res << '\n';
	}

	return 0; 
}