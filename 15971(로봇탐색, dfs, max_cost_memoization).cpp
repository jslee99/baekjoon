#include<iostream>
#include<vector>

using namespace std;

vector<vector<pair<int, int>>> map; // room, cost
int N;
int room1, room2;
int room_checked[100000];
int ans;

void dfs(int room, int cost_sum, int max_single_cost) { // cost_sum until room, max_cost until room
	room_checked[room] = cost_sum - max_single_cost;

	for (int i = 0; i < map[room].size(); i++) {
		if (room_checked[map[room][i].first] == -1) {
			if (max_single_cost < map[room][i].second) {
				dfs(map[room][i].first, cost_sum + map[room][i].second, map[room][i].second);
			}
			else {
				dfs(map[room][i].first, cost_sum + map[room][i].second, max_single_cost);
			}
		}
	}
}

int main(void) {
	int a1, a2, a3;
	cin >> N >> a1 >> a2;
	room1 = a1 - 1;
	room2 = a2 - 1;

	for (int i = 0; i < N; i++) {
		map.push_back(vector<pair<int, int>>());
		room_checked[i] = -1;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a1 >> a2 >> a3;
		map[a1 - 1].push_back(make_pair(a2 - 1, a3));
		map[a2 - 1].push_back(make_pair(a1 - 1, a3));
	}

	dfs(room1, 0, 0);

	cout << room_checked[room2] << endl;
}
