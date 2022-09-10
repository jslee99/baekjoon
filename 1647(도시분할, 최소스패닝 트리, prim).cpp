#include<iostream>
#include<vector>
#include<queue>

struct edge {
	int a, b;
	int weight;
};
struct cmp {
	bool operator()(const struct edge e1, const struct edge e2) {
		return e1.weight > e2.weight;
	}
};
struct cmp2 {
	bool operator()(const struct edge e1, const struct edge e2) {
		return e1.weight < e2.weight;
	}
};
using namespace std;
int N, M;
bool visited[100000];
vector<vector<pair<int, int>>> map;
int tmp = 1001;
priority_queue<struct edge, vector<struct edge>, cmp> pq;
priority_queue<struct edge, vector<struct edge>, cmp2> ans_set;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) map.push_back(vector<pair<int,int>>());
	while (M--) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		map[a1].push_back(make_pair(a2, w));
		map[a2].push_back(make_pair(a1, w));
	}

	visited[0] = true;
	for (int i = 0; i < (int)map[0].size(); i++) {
		struct edge tmp;
		tmp.a = 0, tmp.b = map[0][i].first, tmp.weight = map[0][i].second;
		pq.push(tmp);
	}

	while (!pq.empty()) {
		struct edge cur = pq.top();
		pq.pop();
		if (visited[cur.b]) continue;
		visited[cur.b] = true;
		ans_set.push(cur);
		for (int i = 0; i < (int)map[cur.b].size(); i++) {
			struct edge tmp;
			tmp.a = cur.b, tmp.b = map[cur.b][i].first, tmp.weight = map[cur.b][i].second;
			pq.push(tmp);
		}
	}

	int ans = 0;
	ans_set.pop();
	while (!ans_set.empty()) {
		ans += ans_set.top().weight;
		ans_set.pop();
	}
	cout << ans << endl;
}