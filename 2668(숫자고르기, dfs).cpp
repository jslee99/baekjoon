#include<iostream>
#include<vector>

using namespace std;

vector<int> map[105];
int n;
vector<int> ans;

void dfs(int s, int x, bool visited[], bool& flag) {
	visited[x] = true;

	if (map[x][0] == s) flag = true;

	if (visited[map[x][0]] == false)
		dfs(s, map[x][0], visited, flag);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		map[i].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		bool visited[105];
		bool flag = false;
		for (int j = 1; j <= n; j++)visited[j] = false;
		dfs(i, i, visited, flag);
		if (flag) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}