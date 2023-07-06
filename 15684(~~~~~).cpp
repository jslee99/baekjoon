#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

bool line[11][32];
int N, M, H;
int ans = 99;

void Ladder_game(int max_num) {
	for (int n = 1; n <= N; n++) {
		int cur = n;
		for (int h = 1; h <= H; h++) {
			if (line[cur - 1][h]) {
				cur--;
			}
			else if (line[cur][h]) {
				cur++;
			}
		}
		if (cur != n) return;
	}

	ans = min(ans, max_num);
}

void dfs(int selected_num, int select_h) {
	if (selected_num > 3)return;

	Ladder_game(selected_num);

	for (int h = select_h; h <= H; h++) {
		for (int n = 1; n < N; n++) {
			if (line[n][h] || line[n - 1][h] || line[n + 1][h]) continue;

			line[n][h] = true;
			dfs(selected_num + 1, h);
			line[n][h] = false;
		}
	}
}

int main() {
	cin >> N >> M >> H;

	while (M--) {
		int a, b;
		cin >> a >> b;
		line[b][a] = true;
	}

	dfs(0, 0);
	

	if (ans == 99) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}