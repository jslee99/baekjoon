#include<iostream>
#include<vector>
#include<memory>

using namespace std;

int n, m;
vector<int> map[10005];
int score[10005];
int maxScore = 0;
bool visit[10005];

void dfs(int x, int& curScore) {
	visit[x] = true;
	curScore++;
	for (int i = 0; i < map[x].size(); i++) {
		int y = map[x][i];
		if (!visit[y]) dfs(y, curScore);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		map[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, false, n + 1);
		int curScore = 0;
		dfs(i, curScore);
		score[i] = curScore;
	}

	for (int i = 1; i <= n; i++) {
		maxScore = max(maxScore, score[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (score[i] == maxScore) cout << i << ' ';
	}

	return 0;
}