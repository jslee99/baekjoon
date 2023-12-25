#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TRI {
public:
	int b;
	long long d;
};

struct cmp {
	bool operator() (TRI a, TRI b) {
		return a.d > b.d;
	}
};

int n, m;
vector<pair<int, long long>> map[200005];
bool visit[200005];
priority_queue<TRI, vector<TRI>, cmp> pq;
long long sumCost;
long long minCost;

void reset() {
	for (int i = 0; i < n; i++)
		map[i].clear();

	for (int i = 0; i < n; i++)
		visit[i] = false;

	minCost = 0;
	sumCost = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		reset();

		while (m--) {
			int a, b;
			long long c;
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, c));
			map[b].push_back(make_pair(a, c));
			sumCost += c;
		}

		TRI x;
		x.b = 0;
		x.d = 0;
		pq.push(x);
		while (!pq.empty()) {
			x = pq.top();
			pq.pop();

			if (visit[x.b])
				continue;

			visit[x.b] = true;
			minCost += x.d;
			for (vector<pair<int, long long>>::iterator it = map[x.b].begin(); it != map[x.b].end(); it++) {
				TRI y;
				y.b = it->first;
				y.d = it->second;
				pq.push(y);
			}
		}
		
		cout << sumCost - minCost << '\n';
	}

}