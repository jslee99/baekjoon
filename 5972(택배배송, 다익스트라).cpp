#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>

using namespace std;

class TRI {
public:
	int a;
	int b;
	int d;
};

struct cmp {
	bool operator() (const TRI& a,const TRI& b) {
		return a.d > b.d;
	}
};

int n, m;
int dist[50005];
vector<pair<int, int>> map[50005];
priority_queue<TRI, vector<TRI>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	TRI x;
	x.a = 0;
	x.b = 1;
	x.d = 0;
	pq.push(x);
	while (!pq.empty()) {
		x = pq.top();
		pq.pop();
		if (dist[x.b] <= x.d) continue;
		dist[x.b] = x.d;

		vector<pair<int, int>>::iterator it;
		for (it = map[x.b].begin(); it != map[x.b].end(); it++) {
			pair<int, int> y = *it;
			TRI z;
			z.a = x.b;
			z.b = y.first;
			z.d = x.d + y.second;
			pq.push(z);
		}
	}

	cout << dist[n] << endl;


	return 0;
}