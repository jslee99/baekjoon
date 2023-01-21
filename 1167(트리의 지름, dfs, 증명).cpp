#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int V;
int ans = -1;

void reset_visited() {
	for (int i = 1; i <= V; i++)visited[i] = false;
}

void dfs(int x, int acc_len,int& b, int& max_len) {
	visited[x] = true;
	if (acc_len > max_len) {
		max_len = acc_len;
		b = x;
	}

	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (!visited[graph[x][i].first]) {
			dfs(graph[x][i].first, acc_len + graph[x][i].second, b, max_len);
		}
	}
}

int main(void){
	cin >> V;
	for (int i = 0; i < V; i++) {
		int a, b, w;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;

			cin >> w;
			graph[a].push_back(make_pair(b, w));
		}
	}

	int a = 1;
	int b;
	int max_len = -1;

	reset_visited();
	dfs(a, 0, b, max_len);//a로부터 가장 멀리있는 정점인 b를 찾고 그 max_len를 찾아내기

	max_len = -1;
	reset_visited();
	dfs(b, 0, a, max_len);

	cout << max_len << endl;
}
//https://velog.io/@zioo/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84-%EA%B5%AC%ED%95%98%EA%B8%B0
//https://blogshine.tistory.com/111
