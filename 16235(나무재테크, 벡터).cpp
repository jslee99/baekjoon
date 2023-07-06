#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> tree[10][10];
int add_vitamin[10][10];
int vitamin[10][10];

int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int N, M, K;
int ans = 0;

bool is_in(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

void spring_summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
			int die_vitamin = 0;
			vector<int> alive_tree;

			for (int k = 0; k < (int)tree[i][j].size(); k++) {
				if (vitamin[i][j] >= tree[i][j][k]) {
					vitamin[i][j] -= tree[i][j][k];
					alive_tree.push_back(tree[i][j][k] + 1);
				}
				else {
					die_vitamin += tree[i][j][k] / 2;
				}
			}

			vitamin[i][j] += die_vitamin;
			tree[i][j].clear();
			for (int k = 0; k < (int)alive_tree.size(); k++) {
				tree[i][j].push_back(alive_tree[k]);
			}
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < (int)tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {
					int new_r, new_c;
					for (int m = 0; m < 8; m++) {
						new_r = i + dr[m], new_c = j + dc[m];
						if (is_in(new_r, new_c)) {
							tree[new_r][new_c].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vitamin[i][j] += add_vitamin[i][j];
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> add_vitamin[i][j];
			vitamin[i][j] = 5;
		}
	}

	while (M--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		tree[x][y].push_back(z);
	}

	for (int year = 1; year <= K; year++) {
		spring_summer();
		fall();
		winter();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += (int)tree[i][j].size();
		}
	}

	cout << ans << endl;

}