#include<iostream>
#include<queue>

using namespace std;

char map[10][10];
int n, m, k;

class node {
public:
	int r;
	int c;
	bool visit[10][10] = {false, };
	int d;
};

queue<node> q;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
int ans = 0;

bool isIn(int r, int c) {
	return r > 0 && r <= n && c > 0 && c <= m;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			map[i][j] = s[j - 1];
	}
	
	node x;
	x.r = n, x.c = 1, x.visit[n][1] = true, x.d = 1;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();

		if (x.r == 1 && x.c == m && x.d == k) {
			ans++;
		}

		for (int k = 0; k < 4; k++) {
			int new_r = x.r + dr[k], new_c = x.c + dc[k];
			if (isIn(new_r, new_c) && !x.visit[new_r][new_c] && map[new_r][new_c] != 'T') {
				node y;
				y.r = new_r, y.c = new_c;
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= m; j++)
						y.visit[i][j] = x.visit[i][j];
				y.visit[new_r][new_c] = true;
				y.d = x.d + 1;
				q.push(y);
			}
		}

	}

	cout << ans;

	return 0;
}