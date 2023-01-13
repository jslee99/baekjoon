#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> graph[50001];
vector<int> child[50001];
int parent[50001];
int level[50001];
int go_upward[50001][17];//node���� 2^16��ŭ level�� �ø��� �Ǵ°��

int N, M;

int ret_log_lvl(int x) {
	return ceil(log2((double)level[x]));
}

/*
void dfs1(int x, int lvl) {
	level[x] = lvl;
	for (int i = 0; i < (int)child[x].size(); i++) {
		dfs1(child[x][i], lvl + 1);
	}
}
*/

void dfs1(int x, int lvl) {
	level[x] = lvl;
	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (parent[x] == graph[x][i]) continue;

		child[x].push_back(graph[x][i]);
		parent[graph[x][i]] = x;
		dfs1(graph[x][i], lvl + 1);
	}
}

void dfs2(int x) {
	int log_lvl = ret_log_lvl(x);

	if (x != 1) go_upward[x][0] = parent[x];

	for (int i = 1; i < log_lvl; i++) {
		//2 ^ i go upward
		go_upward[x][i] = go_upward[go_upward[x][i - 1]][i - 1];
	}

	for (int i = 0; i < (int)child[x].size(); i++) {
		dfs2(child[x][i]);
	}
}

int LCA(int x, int y) {
	if (level[x] > level[y]) swap(x, y);
	
	/*
	while (level[y] > level[x]) {
		int y_log_lvl = ret_log_lvl(y);
		for (int i = y_log_lvl - 1; i >= 0; i--) {
			if (level[go_upward[y][i]] >= level[x]) {
				y = go_upward[y][i];
				break;
			}
		}
	}
	*/

	int y_log_lvl = ret_log_lvl(y);
	while (level[y] > level[x]) {
		for (int i = y_log_lvl - 1; i >= 0; i--) {
			if (level[go_upward[y][i]] >= level[x]) {
				y = go_upward[y][i];
				y_log_lvl = i;
				break;
			}
		}
	}

	int xy_log_lvl = ret_log_lvl(y);
	while (go_upward[y][0] != go_upward[x][0]) {
		for (int i = xy_log_lvl - 1; i >= 0; i--) {
			if (go_upward[y][i] != go_upward[x][i]) {
				y = go_upward[y][i], x = go_upward[x][i];
				xy_log_lvl = i;
				break;
			}
		}
	}

	if (y == x) { // x�� y�� ancestor�� ���
		return y;
	}
	else {
		return go_upward[y][0];
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs1(1, 1);

	dfs2(1);

	cin >> M;
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}

	return 0;
}


// (4,6) �̶�� edge�� �����Ҷ� 4�� parent�� 6�� child�� �Ƕ�� Ȯ���� ����.
// �ٽø��� ��� ������ �־������� �׻� ���ڰ� ���� ��带 �ϰ��ǰ� parent�� �δ� ������ Ʈ���� �����ϴ°��� ���� �ʴ�.
// dfs(dfs1)�� ���� graph�� Ž���ذ��� Ʈ���� �����ϴ� ���� ���� ����̴�
// ex 1,3  3,4  2,3 �� �־��� ��츦 �����غ���