#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int, int>> graph[100001];
pair<int,int> parent[100001];
vector<pair<int,int>> child[100001];
int V;
int dp_depth[100001];
int ans = -1;

void dfs_tree(int x) {
	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (parent[x].first != graph[x][i].first) {
			child[x].push_back(make_pair(graph[x][i].first, graph[x][i].second));
			parent[graph[x][i].first].first = x;
			parent[graph[x][i].first].second = graph[x][i].second;
		}
	}

	for (int i = 0; i < (int)graph[x].size(); i++) {
		if (parent[x].first != graph[x][i].first) {
			dfs_tree(graph[x][i].first);
		}
	}
}

struct cmp {
	bool operator () (pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

void dfs_dp(int x) {
	if ((int)child[x].size() == 0) {
		dp_depth[x] = 0;
		ans = max(ans, dp_depth[x]);
	}
	else if ((int)child[x].size() == 1) {
		dfs_dp(child[x][0].first);
		dp_depth[x] = dp_depth[child[x][0].first] + child[x][0].second;
		ans = max(ans, dp_depth[x]);
	}
	else {
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

		for (int i = 0; i < (int)child[x].size(); i++) {
			dfs_dp(child[x][i].first);
			pq.push(make_pair(child[x][i].first, dp_depth[child[x][i].first] + child[x][i].second));
		}
		pair<int, int> alpha = pq.top();
		pq.pop();
		pair<int, int> beta = pq.top();
		pq.pop();

		dp_depth[x] = alpha.second;

		ans = max(ans, alpha.second + beta.second);
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

	dfs_tree(1);

	dfs_dp(1);

	cout << ans << endl;
}


//1 - 2, 1 - 3�� ���� Ʈ������ Ʈ���� ������ 2 - 1 - 3 path�� ���� ��Ÿ���� �ǰ� Ȥ�� 1 - 2, 2 - 3 Ʈ������ Ʈ���� ������ 1 - 2 - 3 path�� ���� ��Ÿ���Եȴ�.
//�̶� '�߽�'�� �Ǵ� ���� 1�̸�, �ִ� ������ ���� path�� �߽� ���� ��Ʈ �ܿ� �ٸ� ��尡 �� �� �ִ�.
//�� Ʈ���� ������ ��� ������ ��带 '�߽�'���� �ϴ� path�� ���� ��Ÿ���� �ǹǷ� ��� ��尡 '�߽�'�� �Ǵ� ��츦 traverse�Ͽ� �ִ� ������ ã�Ƴ��� �ȴ�.
//1967�� ���� Ǯ���̴�