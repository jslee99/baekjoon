#include<iostream>
#include<vector>

using namespace std;

int TC;
//vector<int> tp_sort;

void dfs(int x, bool visited[], vector<int>& tp_sort, vector<int> after_building[]) {
//void dfs(int x, bool visited[], vector<int> after_building[]) {
	visited[x] = true;

	for (int i = 0; i < (int)after_building[x].size(); i++) {
		if (!visited[after_building[x][i]]) dfs(after_building[x][i], visited, tp_sort, after_building);
		//if (!visited[after_building[x][i]]) dfs(after_building[x][i], visited, after_building);
	}

	tp_sort.push_back(x);
}

int main(void) {
	cin >> TC;

	while (TC--) {
		int N, K, W;
		int build_time[1001];
		vector<int> after_building[1001];
		int	total_build_time[1001];
		vector<int> tp_sort;
		//tp_sort.clear();
		bool visited[1001];

		cin >> N >> K;
		
		for (int i = 1; i <= N; i++) {
			cin >> build_time[i];
			total_build_time[i] = build_time[i];
			visited[i] = false;
		}

		while (K--) {
			int X, Y;
			cin >> X >> Y;
			after_building[X].push_back(Y);
		}
		cin >> W;

		tp_sort.push_back(-1);//dummy
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) dfs(i, visited, tp_sort, after_building);
			//if (!visited[i]) dfs(i, visited, after_building);
		}

		vector<int>::iterator ptr = tp_sort.end();
		ptr--;
		for (ptr; ptr != tp_sort.begin(); ptr--) {
			int x = *ptr;
			for (int i = 0; i < (int)after_building[x].size(); i++) {
				total_build_time[after_building[x][i]] = max(total_build_time[after_building[x][i]], total_build_time[x] + build_time[after_building[x][i]]);
			}
		}

		cout << total_build_time[W] << endl;
	}
}