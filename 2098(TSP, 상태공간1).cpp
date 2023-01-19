#include<iostream>

using namespace std;
int map[16][16];
int ans = 99999999;
// start node : 0
int N;

void state(int x, int depth, bool visited[], int before_cost) {
	if (depth == N - 1) {
		visited[x] = true;
		if (map[x][0] == 0) {
			//cut_off
		}
		else {
			ans = min(ans, before_cost + map[x][0]);
		}
		visited[x] = false;
		return;
	}
	else {
		visited[x] = true;
		int sum_cost = before_cost;

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				int min_out_edge_of_i = 99999999;
				if (map[i][0] != 0) {
					min_out_edge_of_i = map[i][0];
				}
				for (int j = 1; j < N; j++) {
					if (!visited[j] && map[i][j] != 0) {
						min_out_edge_of_i = min(min_out_edge_of_i, map[i][j]);
					}
				}
				sum_cost += min_out_edge_of_i;
			}
		}

		//out edge of x
		int min_out_edge_of_x = 99999999;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && map[x][j] != 0) {
				min_out_edge_of_x = min(min_out_edge_of_x, map[x][j]);
			}
		}
		sum_cost += min_out_edge_of_x;


		if (sum_cost >= ans) {
			//cut off
		}
		else {
			for (int j = 0; j < N; j++) {
				if (!visited[j] && map[x][j] != 0) {
					state(j, depth + 1, visited, before_cost + map[x][j]);
				}
			}
		}

		visited[x] = false;
		return;
	}
}

int main(void){
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
