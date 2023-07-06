#include<iostream>
#include<vector>
#include<list>

using namespace std;

list<int> _tree[10][10];//나무의 나이들, 오름차순으로 정렬된 상태로 항상 저장되어 있어야함
int init_vitamin[10][10];
int vitamin[10][10];//양분의 양
int N, M, K;
int ans = 0;

int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool is_in(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

struct tree {
	int r;
	int c;
	list<int>::iterator iter;
};

void spring(vector<struct tree>& dead_tree_start_iterators, vector<struct tree>& breed_tree_iterators) {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			for (list<int>::iterator iter = _tree[r][c].begin(); iter != _tree[r][c].end(); iter++) {
				if (*iter <= vitamin[r][c]) {
					vitamin[r][c] -= *iter;
					(*iter)++;
					if ((*iter) % 5 == 0) {
						struct tree x;
						x.r = r;
						x.c = c;
						x.iter = iter;
						breed_tree_iterators.push_back(x);
					}
				}
				else {
					struct tree x;
					x.r = r;
					x.c = c;
					x.iter = iter;
					dead_tree_start_iterators.push_back(x);
					break;
				}
			}
		}
	}
}

void summer(vector<struct tree>& dead_tree_start_iterators) {
	struct tree x;
	list<int>::iterator cur_iter;
	for (int i = 0; i < (int)dead_tree_start_iterators.size(); i++) {
		x = dead_tree_start_iterators[i];
		cur_iter = x.iter;
		/*
		while (cur_iter != _tree[x.r][x.c].end()) {
			vitamin[x.r][x.c] += (*cur_iter) / 2;
			cur_iter =  _tree[x.r][x.c].erase(cur_iter);
		}*/
		for (cur_iter; cur_iter != _tree[x.r][x.c].end(); cur_iter++) {
			vitamin[x.r][x.c] += (*cur_iter) / 2;
		}

		_tree[x.r][x.c].erase(x.iter, _tree[x.r][x.c].end());
	}
}

void fall(vector<struct tree>& breed_tree_iterators) {
	struct tree x;
	for (int i = 0; i < (int)breed_tree_iterators.size(); i++) {
		x = breed_tree_iterators[i];
		int new_r, new_c;
		for (int k = 0; k < 8; k++) {
			new_r = x.r + dr[k], new_c = x.c + dc[k];
			if (is_in(new_r, new_c)) {
				_tree[new_r][new_c].push_front(1);
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vitamin[i][j] += init_vitamin[i][j];
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { cin >> init_vitamin[i][j]; vitamin[i][j] = 5; }

	while (M--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		_tree[x][y].push_back(z);
	}

	for (int year = 1; year <= K; year++) {
		vector<struct tree> dead_tree_start_iterators;
		vector<struct tree> breed_tree_iterators;

		spring(dead_tree_start_iterators, breed_tree_iterators);
		summer(dead_tree_start_iterators);
		fall(breed_tree_iterators);
		winter();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += (int)_tree[i][j].size();
		}
 	}

	cout << ans << endl;
}