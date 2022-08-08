#include<iostream>
#include<vector>
#include<limits>
#include<queue>

using namespace std;

int V, E;
struct node {
	int node_number;
	int parent;
	vector<pair<int,int>> child;
	int key;
	bool is_in;
	vector<pair<int,int>> adj;
};
struct compare {
	bool operator()(struct node* n1, struct node* n2) {
		return n1->key > n2->key;
	}
};
struct node node_list[10000];
priority_queue<struct node*, vector<struct node*>, compare> node_pq;
int ans = 0;
int weight[10000][10000];

void dfs(int node_num) {
	for (int i = 0; i < (int)node_list[node_num].child.size(); i++) {
		ans += node_list[node_num].child[i].second;
		dfs(node_list[node_num].child[i].first);
	}
}


int main(void) {
	cin >> V >> E;
	for (int i = 0; i < V; i++) {
		node_list[i].node_number = i;
		node_list[i].parent = -1;
		node_list[i].key = numeric_limits<int>::max();
		node_list[i].is_in = false;
	}

	for (int i = 0; i < E; i++) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		node_list[a1].adj.push_back(make_pair(a2, w));
		node_list[a2].adj.push_back(make_pair(a1, w));
		weight[a1][a2] = w;
		weight[a2][a1] = w;
	}

	node_list[0].is_in = true;
	for (int i = 0; i < (int)node_list[0].adj.size(); i++) {
		node_list[node_list[0].adj[i].first].key = node_list[0].adj[i].second;
		node_list[node_list[0].adj[i].first].parent = 0;
		node_pq.push(&node_list[node_list[0].adj[i].first]);
	}
	
	while (!node_pq.empty()) {
		struct node* cur = node_pq.top();
		node_pq.pop();
		if (!cur->is_in) {
			cur->is_in = true;
			node_list[cur->parent].child.push_back(make_pair(cur->node_number, weight[cur->parent][cur->node_number]));
			for (int i = 0; i < (int)cur->adj.size(); i++) {
				if (node_list[cur->adj[i].first].key > cur->adj[i].second && !node_list[cur->adj[i].first].is_in) {
					node_list[cur->adj[i].first].key = cur->adj[i].second;
					node_list[cur->adj[i].first].parent = cur->node_number;
					node_pq.push(&node_list[cur->adj[i].first]);
				}
			}
		}
	}
	dfs(0);


	cout << ans << endl;
}
