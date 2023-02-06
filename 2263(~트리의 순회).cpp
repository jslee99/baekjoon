#include<iostream>

using namespace std;

int n;

int inorder_node_num[100000];
int post_num[100001]; //post_num[i] : node i의 post number , post number는 0 ~ n - 1중 하나
pair<int, int> child[100001];

int ret_root(int inorder_node_num[], int post_num[],pair<int,int> child[], int p, int r) {
	if (p > r) {
		return -1;
	}

	int root, root_idx, max_post = -1;
	for (int i = p; i <= r; i++) {
		if (max_post < post_num[inorder_node_num[i]]) {
			root = inorder_node_num[i];
			max_post = post_num[inorder_node_num[i]];
			root_idx = i;
		}
	}

	int left_child = ret_root(inorder_node_num, post_num, child, p, root_idx - 1);
	int right_child = ret_root(inorder_node_num, post_num, child, root_idx + 1, r);

	child[root].first = left_child;
	child[root].second = right_child;

	return root;
}

void pre_order(int x, pair<int, int> child[]) {
	cout << x << " ";
	if (child[x].first != -1) {
		pre_order(child[x].first, child);
	}
	if (child[x].second != -1) {
		pre_order(child[x].second, child);
	}
}


int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder_node_num[i];
	}

	for (int i = 0; i < n; i++) {
		int node;
		cin >> node;
		post_num[node] = i;
	}

	int root = ret_root(inorder_node_num, post_num, child ,0, n - 1);

	pre_order(root, child);

	return 0;
}