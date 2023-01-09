#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[100001];
vector<int> graph_r[100001];
bool visited[100001];
int T;
int N;
vector<int> node_list; // sort by post
int cnt = 0;

void reset_visited() {
	for (int i = 1; i <= N; i++) visited[i] = false;
}

void reset_graph() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
		graph_r[i].clear();
	}
}

void dfs1(int x) {
	visited[x] = true;
	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (!visited[graph[x][i]]) dfs1(graph[x][i]);
	}
	node_list.push_back(x);
}

void dfs2(int x, bool is_first) {
	visited[x] = true;

	int a = 0;
	for (int i = 0; i < (int)graph_r[x].size(); i++) {
		if (!visited[graph_r[x][i]]) {
			a++;
			dfs2(graph_r[x][i], false);
		}
	}

	if (a == 0 && is_first) {
		if (graph[x][0] != x) cnt++;
	}

	return;
}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> N;
		
		reset_graph();
		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			graph[i].push_back(a);
			graph_r[a].push_back(i);
		}

		node_list.clear();
		reset_visited();
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs1(i);
			}
		}

		cnt = 0;
		reset_visited();
		for (int i = N - 1; i >= 0; i--) {
			if (!visited[node_list[i]]) dfs2(node_list[i], true);
		}

		
		cout << cnt << endl;

		
	}
}