#include<iostream>
#include<queue>

using namespace std;

class node {
public:
	int t;
	int p;
};
int n, k;

node g[100001];
queue<pair<int, pair<int, int>>> q; // cur, time, prev

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= 100000; i++) {
		g[i].t = -1, g[i].p = -1;
	}

	q.push({ n, {0, -1} });
	while (!q.empty()) {
		pair<int, pair<int, int>> x = q.front();
		q.pop();

		int c = x.first;
		int t = x.second.first;
		int p = x.second.second;

		if (g[c].t != -1) continue;

		g[c].t = t, g[c].p = p;

		if (c + 1 <= 100000) {
			q.push({ c + 1, {t + 1, c} });
		}

		if (c - 1 >= 0) {
			q.push({ c - 1, {t + 1, c} });
		}

		if (2 * c <= 100000) {
			q.push({ 2 * c, {t + 1, c} });
		}
	}

	vector<int> ans;
	int x = k;
	while (g[x].p != -1) {
		ans.push_back(x);
		x = g[x].p;
	}
	ans.push_back(x);

	cout << g[k].t << '\n';

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}

	return 0;
}