#include<iostream>
#include<vector>

using namespace std;
int n;
bool inedge_exist[250000];
int map[500][500];
vector<int> graph[250000];
int max_depth[250000];
int live_time[250000];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
int ans = 0;

void update_ans(int depth) {
	ans = max(ans, depth);
}

int from_coordinate_to_node(int r, int c) {
	return n * r + c;
}

bool is_in(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

void dfs(int x, int depth) {
	if (max_depth[x] >= depth) {
		return;
	}
	else {
		max_depth[x] = depth;
	}

	if ((int)graph[x].size() == 0) {
		update_ans(depth);
		return;
	}

	for (int i = 0; i < (int)graph[x].size(); i++) {
		dfs(graph[x][i], depth + 1);
	}
}

int func(int x) {
	if (live_time[x] != 0) {
		return live_time[x];
	}

	live_time[x] = 1;
	for (int i = 0; i < (int)graph[x].size(); i++) {
		live_time[x] = max(live_time[x], 1 + func(graph[x][i]));
	}
	return live_time[x];
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int before_node = i * n + j;
			int new_r, new_c, after_node;
			for (int k = 0; k < 4; k++) {
				new_r = i + dr[k], new_c = j + dc[k], after_node = new_r * n + new_c;
				if (is_in(new_r, new_c) && map[i][j] < map[new_r][new_c]) {
					graph[before_node].push_back(after_node);
					inedge_exist[after_node] = true;
				}
			}
		}
	}

	for (int i = 0; i < n * n; i++) {
		//if (!inedge_exist[i]) {
			//dfs(i, 1);
		//}
		ans = max(ans,func(i));
	}

	cout << ans << endl;
}
