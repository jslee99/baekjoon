#include<iostream>
#include<queue>
#include<limits>

using namespace std;
int map[100][100];
bool is_fixed[100][100];
int cost[100][100];
int R, C;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
struct node_weight {
	int r, c;
	int weight;
};
struct cmp {
	bool operator()(node_weight* a, node_weight* b) {
		return a->weight > b->weight;
	}
};
priority_queue<node_weight*, vector<node_weight*>, cmp> pq;

bool is_in(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C && !is_fixed[r][c];
}

int main(void) {
	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	node_weight* cur = new node_weight;
	cur->r = 0, cur->c = 0, cur->weight = 0;
	pq.push(cur);
	
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		if (is_fixed[cur->r][cur->c]) continue;

		is_fixed[cur->r][cur->c] = true;
		cost[cur->r][cur->c] = cur->weight;
		for (int i = 0; i < 4; i++) {
			int new_r = cur->r + dr[i], new_c = cur->c + dc[i];
			if (!is_in(new_r, new_c)) continue;

			node_weight* tmp = new node_weight;
			tmp->r = new_r, tmp->c = new_c, tmp->weight = cur->weight + map[new_r][new_c];
			pq.push(tmp);
		}
	}

	cout << cost[R - 1][C - 1] << endl;
}