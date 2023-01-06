#include<iostream>
#include<vector>

using namespace std;

vector<int> map[101];
vector<int> map2[101];
int N, M;
//int post_num[101];
//pair<int, int> node_list[100]; // node_num, post_num
//int post = 0;
bool visited[101];

void reset_visited() {
	for (int i = 1; i <= N; i++) visited[i] = false;
}

/*
void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < (int)map[x].size(); i++) {
		if (!visited[map[x][i]]) dfs(map[x][i]);
	}
	post_num[x] = post++;
}

int cmp(const void* a, const void* b) {
	const pair<int, int>* x = (pair<int, int> *)a;
	const pair<int, int>* y = (pair<int, int> *)b;

	if (x->second < y->second) return 1;
	else return 0;
}*/

int dfs1(int x) {
	int res = 1;
	visited[x] = true;
	for (int i = 0; i < (int)map[x].size(); i++) {
		if (!visited[map[x][i]]) res += dfs1(map[x][i]);
	}

	return res;
}

int dfs2(int x) {
	int res = 1;
	visited[x] = true;
	for (int i = 0; i < (int)map2[x].size(); i++) {
		if (!visited[map2[x][i]]) res += dfs2(map2[x][i]);
	}

	return res;
}

int main(void) {
	cin >> N >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;
		// a > b
		map[a].push_back(b);
		map2[b].push_back(a);
	}

	/*
	reset_visited();
	for (int i = 1; i <= N; i++) {
		if(!visited[i]) dfs(i);
	}

	for (int i = 1; i <= N; i++) {
		node_list[i - 1] = make_pair(i, post_num[i]);
	}

	qsort(node_list, N, sizeof(pair<int, int>), cmp);*/

	for (int i = 1; i <= N; i++) {
		reset_visited();
		int a = dfs1(i);
		a--;
		reset_visited();
		int b = dfs2(i);
		b--;
		cout << N - a - b - 1 << endl;
	}

	return 0;
}