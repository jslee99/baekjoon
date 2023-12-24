#include<iostream>
#include<vector>

using namespace std;

int n, t;

class node {
public:
	int p;
	int d;
	vector<int> ch;
};

node tree[10005];
int q, w;

void reset() {
	for (int i = 1; i <= n; i++)
		tree[i].ch.clear(), tree[i].p = -1, tree[i].d = -1;
}

void dfs(int x, int d) {
	tree[x].d = d;
	for (vector<int>::iterator it = tree[x].ch.begin(); it != tree[x].ch.end(); it++) 
		dfs(*it, d + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		reset();

		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			tree[b].p = a;
			tree[a].ch.push_back(b);
		}

		int root;
		for (int i = 1; i <= n; i++) {
			if (tree[i].p == -1)
				root = i;
		}

		dfs(root, 0);

		cin >> q >> w;

		//q => w
		if (tree[q].d < tree[w].d)
			swap(q, w);

		while (tree[q].d > tree[w].d) {
			q = tree[q].p;
		}

		// q == w
		while(q != w){
			q = tree[q].p;
			w = tree[w].p;
		}

		cout << q << '\n';

	}
}
