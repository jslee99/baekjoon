#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> graph[1001];
vector<pair<int, int>> r_graph[1001];
int _time[1001];
int r_time[1001];
int N, M, X;

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main(void) {
	cin >> N >> M >> X;
	while (M--) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back(make_pair(b, t));
		r_graph[b].push_back(make_pair(a, t));
	}
	for (int i = 1; i <= N; i++) _time[i] = -1;

	pq.push(make_pair(X, 0));
	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();
		if (_time[x.first] != -1) continue;

		_time[x.first] = x.second;

		for (int i = 0; i < (int)graph[x.first].size(); i++) {
			pq.push(make_pair(graph[x.first][i].first, _time[x.first] + graph[x.first][i].second));
		}
	}

	for (int i = 1; i <= N; i++) r_time[i] = -1;

	pq.push(make_pair(X, 0));
	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();
		if (r_time[x.first] != -1) continue;

		r_time[x.first] = x.second;

		for (int i = 0; i < (int)r_graph[x.first].size(); i++) {
			pq.push(make_pair(r_graph[x.first][i].first, r_time[x.first] + r_graph[x.first][i].second));
		}
	}

	int _max = 0;
	for (int i = 1; i <= N; i++) _max = max(_max, _time[i] + r_time[i]);

	cout << _max << endl;
}