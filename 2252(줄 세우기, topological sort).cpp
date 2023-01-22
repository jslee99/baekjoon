#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, M;
vector<int> graph[32001];
vector<pair<int, int>> post_node;
bool visited[32001];
int post = 0;

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (!visited[graph[x][i]]) dfs(graph[x][i]);
	}

	post_node.push_back(make_pair(post++, x));
}

int main(void){
	cin >> N >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}

	sort(post_node.begin(), post_node.end(), greater<pair<int,int>>());

	vector<pair<int, int>>::iterator iter;
	for (iter = post_node.begin(); iter != post_node.end(); iter++) {
		cout << (*iter).second << " ";
	}


	return 0;
}
