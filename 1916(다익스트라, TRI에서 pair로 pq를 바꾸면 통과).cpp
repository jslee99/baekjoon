#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

int n, m;
int s, e;

class TRI {
public:
	int a;
	int b;
	long long w;
};

struct cmp {
	bool operator () (TRI a, TRI b) {
		return a.w < b.w;
	}
};

vector<pair<int, long long>> map[1005];
long long visit[1005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) visit[i] = LLONG_MAX;

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back({ b, (long long)c });
	}

	cin >> s >> e;

	pair<long long, int> x;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		x = pq.top();
		pq.pop();

		if (visit[x.second] <= x.first) continue;
		visit[x.second] = x.first;

		for (int i = 0; i < map[x.second].size(); i++) {
			pair<int, long long> p = map[x.second][i];
			if (visit[p.first] <= x.first + p.second) continue;
			pq.push({x.first + p.second, p.first});
		}
	}

	cout << visit[e] << '\n';
}