#include<iostream>
#include<vector>

using namespace std;
vector<int> forward_graph[501];
vector<int> backward_graph[501];
int less_num[501];
int greater_num[501];
bool visited[501];

int N, M, cnt;

void reset_visited() {
	for (int i = 1; i <= N; i++) visited[i] = false;
}

void dfs(int x, vector<int> graph[], int &cnt) {
	visited[x] = true;
	cnt++;

	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (!visited[graph[x][i]]) dfs(graph[x][i], graph, cnt);
	}
}

int main(void){
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		forward_graph[b].push_back(a);
		backward_graph[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		reset_visited();
		int cnt = -1;
		dfs(i, forward_graph, cnt);
		less_num[i] = cnt;
	}
	for (int i = 1; i <= N; i++) {
		reset_visited();
		int cnt = -1;
		dfs(i, backward_graph, cnt);
		greater_num[i] = cnt;
	}

	int cnt2 = 0;
	for (int i = 1; i <= N; i++) {
		if (less_num[i] + greater_num[i] + 1 == N)cnt2++;
	}

	cout << cnt2 << endl;
}
