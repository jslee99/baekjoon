#include<iostream>
#include<queue>

int INF = 99999999;
using namespace std;
int map[16][16];
int ans = INF;
// start node : 0
int N;

int _lower_bound(int x, int depth, bool visited[], int before_cost) {
	int cost_lower_bound = before_cost;
	visited[x] = true;
	if (depth == N - 1) {
		if (map[x][0] == 0) {
			visited[x] = false;
			return INF;
		}
		else {
			visited[x] = false;
			return cost_lower_bound + map[x][0];
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				int min_out_edge_of_i = INF;
				for (int j = 0; j < N; j++) {
					if ((!visited[j] || j == 0) && map[i][j] != 0) {
						min_out_edge_of_i = min(min_out_edge_of_i, map[i][j]);
					}
				}
				cost_lower_bound += min_out_edge_of_i;
			}
		}

		int min_out_edge_of_x = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && map[x][j] != 0) {
				min_out_edge_of_x = min(min_out_edge_of_x, map[x][j]);
			}
		}
		cost_lower_bound += min_out_edge_of_x;

		visited[x] = false;
		return cost_lower_bound;
	}
}

void state(int x, int depth, bool visited[], int before_cost) {
	visited[x] = true;
	if (depth == N - 2) {
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && map[x][j] != 0) {
				pq.push(make_pair(_lower_bound(j, depth + 1, visited, before_cost + map[x][j]), j));
			}
		}

		while (!pq.empty()) {
			pair<int, int> a;
			a = pq.top();
			pq.pop();

			ans = min(ans, a.first);
		}
	}
	else {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && map[x][j] != 0) {
				pq.push(make_pair(_lower_bound(j, depth + 1, visited, before_cost + map[x][j]), j));
			}
		}

		while (!pq.empty()) {
			pair<int, int> a;
			a = pq.top();
			pq.pop();

			if (a.first >= ans) {
				continue;
			}
			else {
				state(a.second, depth + 1, visited, before_cost + map[x][a.second]);
			}
		}
	}
	visited[x] = false;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	bool visited[16];
	for (int i = 0; i < N; i++) visited[i] = false;
	state(0, 0, visited, 0);

	cout << ans << endl;
}

/*
3

0 86 0

69 0 83

45 97 0

답:214

4

0 1 2 3

2 0 3 0

3 0 0 0

1 2 3 0

답: 11

4

0 1 100 100

0 0 3 0

0 200 0 400

1 1 1 0

답:405

16

0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1

1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1

1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1

1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1

1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1

1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1

1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1

1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1

1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1

1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1

1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1

1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1

1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1

1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0

답:16
*/