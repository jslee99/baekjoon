#include<iostream>
#include<vector>

using namespace std;

int ans = 0;

struct node {
	pair<int,int> parent;//node , weight
	vector<pair<int,int>> child;
};
struct node node_lst[10000];
vector<int> leaf_lst;
int n;
bool visited[10000];

void reset_visited() {
	for (int i = 0; i < n; i++) visited[i] = false;
}

void dfs(int node_num, int weight_sum) {
	visited[node_num] = true;

	ans = max(ans, weight_sum);

	if (node_num != 0) {//parent
		if (!visited[node_lst[node_num].parent.first]) {
			dfs(node_lst[node_num].parent.first, weight_sum + node_lst[node_num].parent.second);
		}
	}

	for (int i = 0; i < (int)node_lst[node_num].child.size(); i++) {
		if (!visited[node_lst[node_num].child[i].first]) {
			dfs(node_lst[node_num].child[i].first, weight_sum + node_lst[node_num].child[i].second);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		node_lst[a1].child.push_back(make_pair(a2, w));
		node_lst[a2].parent = make_pair(a1, w);
	}

	for (int i = 0; i < n; i++) {
		if ((int)node_lst[i].child.size() == 0) leaf_lst.push_back(i);
	}

	for (int i = 0; i < (int)leaf_lst.size(); i++) {
		reset_visited();
		dfs(leaf_lst[i], 0);
	}

	cout << ans << endl;
}