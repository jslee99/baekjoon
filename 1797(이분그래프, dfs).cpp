#include<iostream>
#include<vector>

using namespace std;

int K, V, E;
int visited[20001];
vector<int> map[20001];

void reset() {
	for (int i = 1; i <= 20000; i++) {//V <- 20000 에러가난다 why?
		visited[i] = -1;
		map[i].clear();
	}
}

void dfs(int n, int c) {
	visited[n] = c;
	for (int i = 0; i < (int)map[n].size(); i++) {
		if (visited[map[n][i]] == -1) dfs(map[n][i], (c + 1) % 2);
	}
}

int main(void) {

	for (int i = 1; i <= 20000; i++) visited[i] = -1;

	cin >> K;
	while (K--) {
		cin >> V >> E;
		while (E--) {
			int a, b;
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		
		for (int i = 1; i <= 20000; i++) {
			if (visited[i] == -1) dfs(i, 0);
		}

		bool flag = true;
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < (int)map[i].size(); j++) {
				if (visited[i] == visited[map[i][j]]) flag = false;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;

		reset();
	}
}

