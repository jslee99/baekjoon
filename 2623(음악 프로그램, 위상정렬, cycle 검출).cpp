#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> map[1005];
int N, M;
bool cycle = false;
int pre = 1;
int post = 1;
int pre_of[1005];
int post_of[1005];
vector<pair<int, int>> v;

void dfs(int x) {
	pre_of[x] = pre++;

	for (int i = 0; i < (int)map[x].size(); i++) {
		int y = map[x][i];
		if (pre_of[y] == 0) dfs(y);
		else {
			if (post_of[y] == 0) cycle = true;//어떠한 노드의 pre는 설정되어 있고(visited) post가 설정되기 전에(post == 0일떄), dfs를 하게되면서 그 노드로 가는 path가 존재하면 cycle 존재
		}
	}

	post_of[x] = post++;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		vector<int> node;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			node.push_back(a);
		}
		for (int i = 0; i < n - 1; i++) {
			map[node[i]].push_back(node[i + 1]);
		}
	}

	//checking cycle, is there back edge in dfs tree?
	
	for (int i = 1; i <= N; i++) {
		if (pre_of[i] == 0) dfs(i);
	}

	if (cycle) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(make_pair(post_of[i], i));
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i].second << '\n';
	}

	return 0;
}