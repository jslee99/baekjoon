#include<iostream>
#include<queue>
#include<climits>

using namespace std;
int visit[200][200][31];
int map[200][200];
int K;
int R, C;
int ans = INT_MAX;

int dr1[4] = { -1, 0, 1, 0 };
int dc1[4] = { 0, 1, 0, -1 };
int dr2[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dc2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct node {
	int r;
	int c;
	int len;
	int jump;
};

struct cmp {
	bool operator() (const struct node& a, const struct node& b) {
		return a.len > b.len;
	}
};

bool is_in(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

//priority_queue<struct node, vector<struct node>, cmp> pq;
queue<struct node> pq;

int main() {
	cin >> K;
	cin >> C >> R;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> map[i][j];
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) for (int k = 0; k <= K; k++) visit[i][j][k] = -1;


	struct node x, y;
	x.r = 0, x.c = 0, x.jump = 0, x.len = 0;
	pq.push(x);
	while (!pq.empty()) {
		//x = pq.top();
		x = pq.front();
		pq.pop();

		if (x.jump > K || visit[x.r][x.c][x.jump] != -1) continue;
		visit[x.r][x.c][x.jump] = x.len;

		y.jump = x.jump, y.len = x.len + 1;
		for (int i = 0; i < 4; i++) {
			y.r = x.r + dr1[i], y.c = x.c + dc1[i];
			if (is_in(y.r, y.c) && map[y.r][y.c] == 0) {
				pq.push(y);
			}
		}

		y.jump = x.jump + 1;
		for (int i = 0; i < 8; i++) {
			y.r = x.r + dr2[i], y.c = x.c + dc2[i];
			if (is_in(y.r, y.c) && map[y.r][y.c] == 0) {
				pq.push(y);
			}
		}
	}

	for (int k = 0; k <= K; k++) {
		if (visit[R - 1][C - 1][k] != -1) {
			ans = min(ans, visit[R - 1][C - 1][k]);
		}
	}

	if (ans != INT_MAX) cout << ans << endl;
	else cout << -1 << endl;
}