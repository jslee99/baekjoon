#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class pos{
public:
	int i;
	int r;
	int c;
	int f;
	int v;
};

int n;
int f[405][5];
int map[25][25];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool isIn(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

int friendNum(int i, int r, int c) {
	int nn = 0;
	int rr, cc;
	for (int k = 0; k < 4; k++) {
		rr = r + dr[k], cc = c + dc[k];
		if (!isIn(rr, cc)) continue;
		
		for (int m = 1; m < 5; m++) {
			if (f[i][m] == map[rr][cc]) nn++;
		}
	}
	return nn;
}


bool isFriend(int i, int a) {
	for (int j = 1; j < 5; j++) {
		if (a == f[i][j]) return true;
	}
	return false;
}

bool isEmpt(int r, int c) {
	return map[r][c] == -1;
}

bool cmp(const pos& a, const pos& b) {
	if (a.f > b.f) {
		return true;
	}
	else if (a.f < b.f) {
		return false;
	}
	else {
		if (a.v > b.v) {
			return true;
		}
		else if (a.v < b.v) {
			return false;
		}
		else {
			if (a.r < b.r) {
				return true;
			}
			else if (a.r > b.r) {
				return false;
			}
			else {
				if (a.c < b.c) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

void check(pos& x) {
	int r, c;
	for (int k = 0; k < 4; k++) {
		r = x.r + dr[k], c = x.c + dc[k];
		if (!isIn(r, c)) continue;

		if (isFriend(x.i, map[r][c])) x.f++;

		if (isEmpt(r, c)) x.v++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> f[i][j];
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] = -1;

	for (int i = 0; i < n * n; i++) {

		vector<pos> cand;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if (map[r][c] != -1) continue;

				pos x;
				x.i = i, x.r = r, x.c = c, x.f = 0, x.v = 0;
				check(x);
				cand.push_back(x);
			}
		}

		sort(cand.begin(), cand.end(), cmp);
		map[cand[0].r][cand[0].c] = f[i][0];
	}

	int ans = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			int m = map[r][c];
			int i;
			for (i = 0; i < n * n; i++) {
				if (m == f[i][0]) break;
			}
			int nn = friendNum(i, r, c);

			switch (nn) {
			case 1:
				ans += 1;
				break;
			case 2:
				ans += 10;
				break;
			case 3:
				ans += 100;
				break;
			case 4:
				ans += 1000;
				break;
			}
		}
	}

	cout << ans << '\n';
}