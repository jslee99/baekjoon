#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;
int n, m;
bool visited[500];

void dfs(int a, int depth) {
	if (depth == 3) return;

	visited[a] = true;
	for (int i = 0; i < (int)v[a].size(); i++) 
		dfs(v[a][i], depth + 1);
	
}

int main(void){
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		v.push_back(vector<int>());
	}
	for (int i = 0; i < m; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		v[a1 - 1].push_back(a2 - 1);
		v[a2 - 1].push_back(a1 - 1);
	}
	visited[0] = true;
	dfs(0, 0);
	int ans = 0;
	for (int i = 1; i < n; i++) if (visited[i]) ans++;

	cout << ans << endl;
}