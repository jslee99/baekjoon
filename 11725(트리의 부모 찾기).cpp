#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int N; // max 100000;
class node {
public:
	vector<int> adj;
	int parent;
	vector<int> child;
};
node lst[100005];

void dfs1(int x, int p) {
	lst[x].parent = p;
	int len = (int)lst[x].adj.size();
	for (int i = 0; i < len; i++) {
		int c = lst[x].adj[i];
		if (p == c) continue;

		lst[x].child.push_back(c);
	}

	len = (int)lst[x].child.size();
	for (int i = 0; i < len; i++) {
		int c = lst[x].child[i];
		dfs1(c, x);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lst[a].adj.push_back(b);
		lst[b].adj.push_back(a);
	}

	dfs1(1, 0);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", lst[i].parent);
	}
}