#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int build_time[501];
int min_time[501];
bool visited[501];
vector<pair<int, int>> tp_sort;
int post = 1;
vector<int> build_order[501];

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < (int)build_order[x].size(); i++) {
		if (!visited[build_order[x][i]]) {
			dfs(build_order[x][i]);
		}
	}
	tp_sort.push_back(make_pair(x, post++));
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		build_time[i] = a;
		
		cin >> a;
		while (a != -1) {
			build_order[a].push_back(i);
			cin >> a;
		}
	}


	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}

	sort(tp_sort.begin(), tp_sort.end(), cmp);

	vector<pair<int, int>>::iterator iter;
	for (iter = tp_sort.begin(); iter != tp_sort.end(); iter++) {
		pair<int, int> x = *iter;
		min_time[x.first] = min_time[x.first] + build_time[x.first];
		for (int i = 0; i < (int)build_order[x.first].size(); i++) {
			min_time[build_order[x.first][i]] = max(min_time[build_order[x.first][i]], min_time[x.first]);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << min_time[i] << endl;
	}

	return 0;
}
