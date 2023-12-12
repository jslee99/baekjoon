#include<iostream>
#include<queue>

using namespace std;

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int d, n;
int dist[10005];
pair<pair<int, int>, int> way[20];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // 위치, 거리

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		way[i].first.first = a, way[i].first.second = b, way[i].second = c;
	}

	for (int i = 0; i <= d; i++)
		dist[i] = -1;

	pq.push(make_pair(0, 0));

	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();

		if (dist[x.first] != -1) continue;

		dist[x.first] = x.second;

		if (x.first + 1 <= d)
			pq.push(make_pair(x.first + 1, x.second + 1));

		for (int i = 0; i < n; i++) {
			if (way[i].first.first == x.first) {
				pq.push(make_pair(way[i].first.second, x.second + way[i].second));
			}
		}
	}

	cout << dist[d] << '\n';
}