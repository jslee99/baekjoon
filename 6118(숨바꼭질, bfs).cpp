#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> map[20005];
int n, m;
int dist[20005];
queue<pair<int, int>> q;

int main() {
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		dist[i] = 50005;

	q.push(make_pair(1, 0));
	dist[1] = 0;

	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		//if (dist[x.first] < x.second) continue;
		//dist[x.first] = x.second;

		vector<int>::iterator it;
		for (it = map[x.first].begin(); it != map[x.first].end(); it++) {
			if (dist[*it] > x.second + 1) {
				dist[*it] = x.second + 1;
				q.push(make_pair(*it, x.second + 1));
			}
		}
	}


	int min_dist = -1;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		min_dist = max(min_dist, dist[i]);

	for (int i = 1; i <= n; i++)
		if (dist[i] == min_dist)
			ans.push_back(i);

	cout << *ans.begin() << ' ' << min_dist << ' ' << ans.size() << '\n';

}