#include<iostream>
#include<vector>

using namespace std;
int n, m;
int a1, a2;
int ans = -1;
struct node {
	node* parent;
	vector<node*> child;// parent, child~~~
	bool visited;
};
node* p_list[100];

void dfs(node* cur, int depth) {
	cur->visited = true;
	if (cur == p_list[a1]) {
		ans = depth;
	}

	if (cur->parent != NULL && !cur->parent->visited) dfs(cur->parent, depth + 1);

	for (int i = 0; i < (int)cur->child.size(); i++) {
		if(!cur->child[i]->visited) dfs(cur->child[i], depth + 1);
	}
}

int main(void) {
	cin >> n >> a1 >> a2;
	a1--, a2--;

	for (int i = 0; i < n; i++) {
		p_list[i] = new node;
	}

	for (int i = 0; i < n; i++) {
		p_list[i]->parent = NULL;
		p_list[i]->child = vector<node*>();
		p_list[i]->visited = false;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int b1, b2;
		cin >> b1 >> b2;
		b1--, b2--;//parent, child
		p_list[b1]->child.push_back(p_list[b2]);
		p_list[b2]->parent = p_list[b1];
	}

	dfs(p_list[a2], 0);

	cout << ans << endl;
}