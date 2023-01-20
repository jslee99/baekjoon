#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> graph[1000001];
int parent[1000001];
vector<int> child[1000001];
int dp[1000001][2]; // x가 EA아닐때, EA일때 필요한 EA의 최소 개수(자신을 root로 하는 subtree에서)
int N;
int INF = 1000001;
int ans;

void dfs_tree(int x) {
	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (parent[x] != graph[x][i]) {
			child[x].push_back(graph[x][i]);
			parent[graph[x][i]] = x;
			dfs_tree(graph[x][i]);
		}
	}
}

int dfs_dp(int x, bool ea){
	if (dp[x][ea] != -1) return dp[x][ea];

	if (ea) {
		if ((int)child[x].size() == 0) {
			dp[x][ea] = 1;
			return dp[x][ea];
		}

		dp[x][ea] = 1;
		for (int i = 0; i < (int)child[x].size(); i++) {
			dp[x][ea] += min(dfs_dp(child[x][i], false), dfs_dp(child[x][i], true));
		}
		return dp[x][ea];
	}
	else {
		if ((int)child[x].size() == 0) {
			dp[x][ea] = 0;
			return dp[x][ea];
		}

		dp[x][ea] = 0;
		for (int i = 0; i < (int)child[x].size(); i++) {
			dp[x][ea] += dfs_dp(child[x][i], true);
		}
		return dp[x][ea];
	}
}

void reset_dp() {
	for (int i = 1; i <= N; i++) dp[i][0] = -1, dp[i][1] = -1;
}

int main(void){
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs_tree(1);

	reset_dp();
	ans = dfs_dp(1, true);
	reset_dp();
	ans = min(ans, dfs_dp(1, false));
	cout << ans << endl;
}
