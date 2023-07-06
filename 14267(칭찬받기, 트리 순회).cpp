#include<iostream>
#include<vector>

using namespace std;

class member {
public:
	vector<int> ch;
	int dd;
	int tt;
};

member members[100005];
int n;
int m;

void dfs(int x, int sum) {
	members[x].tt = sum + members[x].dd;
	for (int i = 0; i < members[x].ch.size(); i++) {
		dfs(members[x].ch[i], members[x].tt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) members[i].dd = 0, members[i].tt = 0;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == -1)continue;

		members[a].ch.push_back(i);
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		members[a].dd += b;
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		cout << members[i].tt << ' ';
	}
}