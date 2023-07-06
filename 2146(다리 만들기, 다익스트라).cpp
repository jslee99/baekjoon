#include<iostream>
#include<queue>
#include<climits>

using namespace std;
int map[100][100];
int N;
int island_num = 2;
int ans = INT_MAX;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

bool is_in(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

void mark_dfs(int r, int c, int num) {
	map[r][c] = num;
	int new_r, new_c;
	for (int k = 0; k < 4; k++) {
		new_r = r + dr[k], new_c = c + dc[k];
		if (is_in(new_r, new_c) && map[new_r][new_c] == 1) {
			mark_dfs(new_r, new_c, num);
		}
	}
}

void mark_island() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				mark_dfs(i, j, island_num++);
			}
		}
	}
}

struct node{
	int r;
	int c;
	int cost;
};

struct cmp {
	bool operator() (const struct node& a, const struct node& b) {
		return a.cost > b.cost;
	}
};

int min_dist_from(const int num) {
	int min_cost[100][100];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) min_cost[i][j] = -1;
	priority_queue<struct node, vector<struct node>, cmp> pq;

	struct node x, y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == num) {
				x.r = i, x.c = j, x.cost = 0;
			}
		}
	}

	pq.push(x);

	while (!pq.empty()) {
		x = pq.top();
		pq.pop();

		if (min_cost[x.r][x.c] != - 1) continue;

		min_cost[x.r][x.c] = x.cost;

		for (int k = 0; k < 4; k++) {
			y.r = x.r + dr[k], y.c = x.c + dc[k];
			if (is_in(y.r, y.c)) {
				if (map[y.r][y.c] == 0) {
					y.cost = x.cost + 1;
				}
				else if (map[y.r][y.c] == num) {
					y.cost = x.cost;
				}
				else {
					y.cost = x.cost;
					return x.cost;
				}

				pq.push(y);
			}

		}
	}


	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];

	mark_island();

	for (int i = 2; i < island_num; i++) {
		int res = min_dist_from(i);
		ans = min(res, ans);
	}

	cout << ans << endl;
}