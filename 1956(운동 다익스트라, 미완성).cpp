#include<iostream>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

struct cmp {
	bool operator()(const pair<int, int> a, const pair<int, int> b) {
		return a.second > b.second;
	}
};
int V, E;
vector<vector<pair<int, int>>> map;
vector<vector<pair<int, int>>> can_return;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
int visited[400];
int ans = numeric_limits<int>::max();

int main(void) {
	cin >> V >> E;

	for (int i = 0; i < V; i++) map.push_back(vector<pair<int, int>>()), can_return.push_back(vector<pair<int,int>>());//, visited[i] = -1;

	for (int i = 0; i < E; i++) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		map[a1].push_back(make_pair(a2, w));
		can_return[a2].push_back(make_pair(a1, w));
	//	if (a2 == 0) can_return.push_back(make_pair(a1, w));
	}

	

	for (int start = 0; start < V; start++) {
		for (int i = 0; i < V; i++) visited[i] = -1;
		pq.push(make_pair(start, 0));

		while (!pq.empty()) {
			pair<int, int> cur = pq.top();
			pq.pop();

			if (visited[cur.first] != -1) continue;

			visited[cur.first] = cur.second;
			for (int i = 0; i < (int)map[cur.first].size(); i++) {
				if (visited[map[cur.first][i].first] != -1) continue;
				pq.push(make_pair(map[cur.first][i].first, map[cur.first][i].second));
			}
		}

		for (int i = 0; i < (int)can_return[start].size(); i++) {
			if (visited[can_return[start][i].first] == -1) continue;
			ans = min(ans, visited[can_return[start][i].first] + can_return[start][i].second);
		}
		

		
	}

	if (ans == numeric_limits<int>::max()) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}