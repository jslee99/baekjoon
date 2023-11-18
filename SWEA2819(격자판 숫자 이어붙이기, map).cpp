#include<iostream>
#include<vector>
#include<map>

using namespace std;

int T;
int mm[4][4];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
map<string, bool> m;

bool isIn(int r, int c) {
	return r >= 0 && r < 4 && c >= 0 && c < 4;
}

void dfs(int r, int c, string& s) {
	if (s.size() > 6) {
		std::map<string, bool>::iterator it = m.find(s);
		if (it == m.end())m.insert(make_pair(s, true));
		return;
	}

	s.push_back(mm[r][c] + '0');
	for (int k = 0; k < 4; k++) {
		int new_r = r + dr[k], new_c = c + dc[k];
		if (isIn(new_r, new_c))dfs(new_r, new_c, s);
	}
	s.erase(s.size() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	cin >> T;
	for (int t = 1; t <= T; t++) {
		m.clear();
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> mm[i][j];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string s;
				dfs(i, j, s);
			}
		}

		cout << '#' << t << ' ' << m.size() << '\n';
	}
}