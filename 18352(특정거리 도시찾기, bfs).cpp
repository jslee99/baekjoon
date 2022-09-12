#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, K, X;
vector<vector<int>> map;
int visited[300001];
queue<pair<int, int>> q;

int main(void) {
	cin >> N >> M >> K >> X;

	for (int i = 0; i <= N; i++)map.push_back(vector<int>());
	for (int i = 1; i <= N; i++) visited[i] = -1;

	while (M--) {
		int a1, a2;
		cin >> a1 >> a2;
		map[a1].push_back(a2);
	}

	q.push(make_pair(X, 0));

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (visited[cur.first] != -1) continue;

		visited[cur.first] = cur.second;
		for (int i = 0; i < (int)map[cur.first].size(); i++) {
			if (visited[map[cur.first][i]] != -1) continue;

			q.push(make_pair(map[cur.first][i], cur.second + 1));
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == K) cout << i << endl, cnt++;
	}

	if (!cnt) {
		cout << "-1" << endl;
	}
}