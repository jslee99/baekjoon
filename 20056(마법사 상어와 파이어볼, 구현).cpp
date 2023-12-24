#include<iostream>
#include<vector>

using namespace std;
int n, m, k;

int dr[8] = { -1, -1, 0, 1, 1, 1,0,  -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

class fire {
public:
	int m;
	int d;
	int s;
};

vector<fire> map[55][55];
vector<fire> tmp[55][55];

int ch(int x) {
	if (0 <= x && x < n)
		return x;
	else if (x < 0) {
		int cmd = (x % n);
		if (cmd == 0)
			return 0;
		else
			return n + cmd;
	}
	else {
		return x % n;
	}
}

int main() {

	cin >> n >> m >> k;

	while (m--) {
		int r, c, m, s, d;
		fire x;
		cin >> r >> c >> m >> s >> d;
		x.m = m, x.s = s, x.d = d;
		map[r - 1][c - 1].push_back(x);
	}

	while (k--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (vector<fire>::iterator it = map[i][j].begin(); it != map[i][j].end(); it++) {
					fire y;
					int r = i + dr[it->d] * it->s, c = j + dc[it->d] * it->s;
					r = ch(r), c = ch(c);
					y.d = it->d, y.m = it->m, y.s = it->s;
					tmp[r][c].push_back(y);
				}
				map[i][j].clear();
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tmp[i][j].size() == 1) {
					map[i][j].push_back(*tmp[i][j].begin());
				}else if (tmp[i][j].size() > 1) {
					int sumM = 0;
					int sumS = 0;
					bool isAllEven = true;
					bool isAllOdd = true;
					for (vector<fire>::iterator it = tmp[i][j].begin(); it != tmp[i][j].end(); it++) {
						sumM += it->m;
						sumS += it->s;
						if (it->d % 2 == 0) {
							isAllOdd = false;
						}
						else {
							isAllEven = false;
						}
					}

					bool isAll = isAllEven || isAllOdd;
					
					for (int k = 0; k < 4; k++) {
						fire x;
						if (isAll) {
							x.d = 2 * k;
						}
						else {
							x.d = 2 * k + 1;
						}
						x.m = sumM / 5;
						x.s = sumS / tmp[i][j].size();
						if (x.m > 0) {
							map[i][j].push_back(x);
						}
					}
				}
				tmp[i][j].clear();
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (vector<fire>::iterator it = map[i][j].begin(); it != map[i][j].end(); it++)
				ans += it->m;

	cout << ans;
}