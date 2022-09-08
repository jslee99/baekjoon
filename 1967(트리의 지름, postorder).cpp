#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int ans = 0;

struct node {
	pair<int,int> parent;//node , weight
	vector<pair<int,int>> child;
	priority_queue<int> depth_pq;
};
struct node node_lst[10000];
vector<int> leaf_lst;
int n;

int postorder(int node) {
	if (node_lst[node].child.size() == 0) {
		if (node == 0) return 0;

		return node_lst[node].parent.second;
	}

	for (int i = 0; i < node_lst[node].child.size(); i++) {
		node_lst[node].depth_pq.push(postorder(node_lst[node].child[i].first));
	}

	if (node_lst[node].depth_pq.size() == 1) {
		ans = max(ans, node_lst[node].depth_pq.top());
		return node_lst[node].depth_pq.top() + node_lst[node].parent.second;
	}
	else {
		int one, two;
		one = node_lst[node].depth_pq.top();
		node_lst[node].depth_pq.pop();
		two = node_lst[node].depth_pq.top();
		ans = max(ans, one + two);
		return one + node_lst[node].parent.second;
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

	postorder(0);

	cout << ans << endl;
}