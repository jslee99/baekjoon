#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

struct node {
	int node_num;
	int cost;
	int before_node;
};

struct cmp {
	bool operator() (const struct node& a, const struct node& b) {
		if (a.cost > b.cost) {
			return true;
		}
		else if (a.cost == b.cost) {
			return a.before_node > b.before_node;
		}
		else {
			return false;
		}
	}
};

using namespace std;
vector<pair<int, int>> map[1001]; // 
pair<int, int> visited[1001];// cost, before_node
priority_queue<struct node, vector<struct node>, cmp> pq;
vector<int> reverse_path;
int n;
int m;
int s, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		map[a].push_back(make_pair(b, w));
	}
	cin >> s >> e;

	for (int i = 1; i <= n; i++) visited[i].first = -1, visited[i].second = -1;
	struct node x;
	x.node_num = s;
	x.cost = 0;
	x.before_node = -1;
	pq.push(x);

	while (!pq.empty()) {
		x = pq.top();
		pq.pop();

		if (visited[x.node_num].first != -1) continue;

		visited[x.node_num].first = x.cost;
		visited[x.node_num].second = x.before_node;

		struct node y;
		for (int i = 0; i < (int)map[x.node_num].size(); i++) {
			y.node_num = map[x.node_num][i].first;
			y.cost = x.cost + map[x.node_num][i].second;
			y.before_node = x.node_num;
			pq.push(y);
		}
	}

	reverse_path.push_back(e);
	while (visited[*(reverse_path.end() - 1)].second != -1) {
		reverse_path.push_back(visited[*(reverse_path.end() - 1)].second);
	}

	cout << visited[e].first << '\n';
	cout << reverse_path.size() << '\n';
	for (vector<int>::reverse_iterator r_iter = reverse_path.rbegin(); r_iter != reverse_path.rend(); r_iter++) {
		cout << *r_iter << ' ';
	}
}