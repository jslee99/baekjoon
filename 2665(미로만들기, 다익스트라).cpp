#include<iostream>
#include<queue>

using namespace std;
int map[50][50];
int visited[50][50];
int n;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
bool is_in(int r, int  c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}
struct node {
	int r, c, weight;
};
struct cmp {
	bool operator()(const node n1, const node n2) {
		return n1.weight > n2.weight;
	}
};
priority_queue<node, vector<node>, cmp> pq;

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = (int)(str[j] - '0');
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visited[i][j] = -1;

	node s;
	s.r = 0, s.c = 0, s.weight = 0;
	pq.push(s);

	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		if (visited[cur.r][cur.c] != -1) continue;

		visited[cur.r][cur.c] = cur.weight;

		for (int i = 0; i < 4; i++) {
			node next;
			next.r = cur.r + dr[i], next.c = cur.c + dc[i];
			if (!is_in(next.r, next.c) || visited[next.r][next.c] != -1) continue;

			next.weight = cur.weight;
			if (map[next.r][next.c] == 0) next.weight++;
			pq.push(next);
		}
	}

	cout << visited[n - 1][n - 1] << endl;
}