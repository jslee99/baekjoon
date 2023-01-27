#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, E;
int v1, v2;
vector<pair<int, int>> map[801];

struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

int dijkstra(int start, int end) {
	int min_dist[801];
	for (int i = 1; i <= N; i++) min_dist[i] = -1;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		pair<int, int> x;
		x = pq.top();
		pq.pop();
		if (min_dist[x.first] != -1) continue;

		min_dist[x.first] = x.second;
		for (int i = 0; i < (int)map[x.first].size(); i++) {
			pq.push(make_pair(map[x.first][i].first, min_dist[x.first] + map[x.first][i].second));
		}
	}

	return min_dist[end];
}

int main(void) {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	int s_v1 = dijkstra(1, v1);
	int s_v2 = dijkstra(1, v2);
	int v1_v2 = dijkstra(v1, v2);
	int v2_v1 = dijkstra(v2, v1);
	int v1_e = dijkstra(v1, N);
	int v2_e = dijkstra(v2, N);

	bool is_can_1, is_can_2;
	is_can_1 = (s_v1 != -1 && v1_v2 != -1 && v2_e != -1);
	is_can_2 = (s_v2 != -1 && v2_v1 != -1 && v1_e != -1);
	if (is_can_1 && is_can_2) {
		cout << min(s_v1 + v1_v2 + v2_e, s_v2 + v2_v1 + v1_e) << endl;
	}
	else if (is_can_1 && !is_can_2) {
		cout << s_v1 + v1_v2 + v2_e << endl;
	}
	else if (!is_can_1 && is_can_2) {
		cout << s_v2 + v2_v1 + v1_e << endl;
	}
	else {
		cout << -1 << endl;
	}

	
}