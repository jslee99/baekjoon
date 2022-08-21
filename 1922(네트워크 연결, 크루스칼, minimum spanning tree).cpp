#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, M;
vector<vector<pair<int,int>>> adj;
bool is_selected[1000];
struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;//node number, weight
int ans = 0;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) adj.push_back(vector<pair<int,int>> ());

	for (int i = 0; i < M; i++) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		adj[a1].push_back(make_pair(a2, w));
		adj[a2].push_back(make_pair(a1, w));
	}

	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (!is_selected[cur.first]) {
			is_selected[cur.first] = true;
			ans += cur.second;
			for (int i = 0; i < (int)adj[cur.first].size(); i++) {
				if (!is_selected[adj[cur.first][i].first]) {
					pq.push(make_pair(adj[cur.first][i].first, adj[cur.first][i].second));
				}
			}
		}
	}

	cout << ans << endl;
}