#include<iostream>
#include<queue>

using namespace std;

int N;
int map[20][20];
int fish_size = 2;
int eat_fish = 0;
pair<int, int> fish_position;
int _time = 0;
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

struct node {
	int row;
	int col;
	int dist;
};

bool is_in(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

/*
int bfs() {
	queue<pair<int, int>> q;
	bool visited[20][20];
 	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visited[i][j] = false;

	int plus_time;

	q.push(make_pair(fish_position.first, fish_position.second));

	while (!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		if (visited[x.first][x.second]) continue;

		visited[x.first][x.second] = true;

		if (map[x.first][x.second] != 0 && map[x.first][x.second] < fish_size) {
			map[x.first][x.second] = 0;
			eat_fish++;
			if (eat_fish == fish_size) {
				fish_size++;
				eat_fish = 0;
			}
			int res = abs(x.first - fish_position.first) + abs(x.second - fish_position.second);
			fish_position.first = x.first, fish_position.second = x.second;
			return res;
		}

		int new_r, new_c;
		for (int i = 0; i < 4; i++) {
			new_r = x.first + dr[i], new_c = x.second + dc[i];
			if (is_in(new_r, new_c) && map[new_r][new_c] <= fish_size && !visited[new_r][new_c]) {
				q.push(make_pair(new_r, new_c));
			}
		}
	}

	return 0;
}
*/

struct cmp {
	bool operator()(struct node a, struct node b) {
		if (a.dist > b.dist) {
			return true;
		}
		else if (a.dist < b.dist) {
			return false;
		}
		else {
			if (a.row > b.row) {
				return true;
			}
			else if (a.row < b.row) {
				return false;
			}
			else {
				if (a.col > b.col) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
};

int bfs() {
	priority_queue<struct node, vector<struct node>, cmp> pq;
	bool visited[20][20];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visited[i][j] = false;

	int plus_time;

	struct node start;
	start.row = fish_position.first, start.col = fish_position.second, start.dist = 0;
	pq.push(start);

	while (!pq.empty()) {
		struct node x = pq.top();
		pq.pop();
		if (visited[x.row][x.col]) continue;

		visited[x.row][x.col] = true;

		if (map[x.row][x.col] != 0 && map[x.row][x.col] < fish_size) {
			map[x.row][x.col] = 0;
			eat_fish++;
			if (eat_fish == fish_size) {
				fish_size++;
				eat_fish = 0;
			}
			int res = x.dist;
			fish_position.first = x.row, fish_position.second = x.col;
			return res;
		}

		int new_r, new_c;
		for (int i = 0; i < 4; i++) {
			new_r = x.row + dr[i], new_c = x.col + dc[i];
			if (is_in(new_r, new_c) && map[new_r][new_c] <= fish_size && !visited[new_r][new_c]) {
				struct node y;
				y.row = new_r, y.col = new_c, y.dist = x.dist + 1;
				pq.push(y);
			}
		}
	}

	return 0;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				fish_position.first = i, fish_position.second = j;
				map[i][j] = 0;
			}
		}
	}

	int delta_time;
	while (delta_time = bfs()) {
		_time += delta_time;
	}
	
	cout << _time << endl;
}