#include<iostream>
#include<vector>

using namespace std;

int N;
int M;
vector<int> map[2000];
int ans = 0;
int visit[2000];

void dfs(int node, int depth) {
	if (depth < 4) {
		visit[node] = 1;
		for (int i = 0; i < map[node].size(); i++) {
			if(visit[map[node][i]] == 0)
				dfs(map[node][i], depth + 1);
		}
		visit[node] = 0;
	}
	else {
		//visit[node] = 1 \n visit[node] = 0;
		ans = 1;
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		map[a1].push_back(a2);
		map[a2].push_back(a1);
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 0);
	}

	cout << ans << endl;
}