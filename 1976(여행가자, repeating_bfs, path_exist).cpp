#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, M;
bool path_exist[200][200];
vector<vector<int>> adj;//a,b ->   a,b adjacency
queue<int> dest;

void bfs(int _start) {
	bool visited[200];
	for (int i = 0; i < N; i++) visited[i] = false;
	queue<int> q;
	q.push(_start);
	visited[_start] = true;
	path_exist[_start][_start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < (int)adj[cur].size(); i++) {
			if (!visited[adj[cur][i]]) {
				visited[adj[cur][i]] = true;
				path_exist[_start][adj[cur][i]] = true;
				q.push(adj[cur][i]);
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		adj.push_back(vector<int>());
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a1;
			cin >> a1;
			if (a1 == 1) {
				adj[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int a1;
		cin >> a1;
		dest.push(a1 - 1);
	}

	for (int i = 0; i < N; i++) {
		bfs(i);
	}

	if (M == 1) {
		cout << "YES" << endl;
	}
	else {
		bool flag = true;
		int a, b;

		b = dest.front();
		dest.pop();

		while (!dest.empty()) {
			a = b;
			b = dest.front();
			dest.pop();
			if (!path_exist[a][b]) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
