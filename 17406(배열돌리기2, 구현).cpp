#include<iostream>
#include<vector>

using namespace std;
int n, m, k;
int a[105][105];
int cp[105][105];
int tmp[105][105];
int tmp2[105][105];
pair<pair<int, int>, int> op[10];
int ans = 99999999;

bool contain(vector<int>& v, int x) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		if (*it == x)
			return true;
	}
	return false;
}

void reset() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cp[i][j] = a[i][j];
}

void rotation(int r, int c, int s) {
	int r1 = r - s, c1 = c - s;
	int r2 = r + s, c2 = c + s;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			tmp[i - r1 + 1][j - c1 + 1] = cp[i][j];
		}
	}

	int tmpr = r2 - r1 + 1;
	int tmpc = c2 - c1 + 1;

	for (int i = 1; i <= tmpr; i++) {
		for (int j = 1; j <= tmpc; j++) {
			if (i == (tmpr + 1) / 2 && j == (tmpc + 1) / 2) {
				tmp2[i][j] = tmp[i][j];
			}
			else if (1 <= i && i <= tmpr / 2 && i < j && j <= tmpc - i + 1) {
				tmp2[i][j] = tmp[i][j - 1];
			}
			else if (tmpc / 2 + 1 < j && j <= tmpc && tmpc - j + 1 < i && i <= j) {
				tmp2[i][j] = tmp[i - 1][j];
			}
			else if (tmpr / 2 + 1 < i && i <= tmpr && tmpc - i + 1 <= j && j < i) {
				tmp2[i][j] = tmp[i][j + 1];
			}
			else {
				tmp2[i][j] = tmp[i + 1][j];
			}
		}
	}

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			cp[i][j] = tmp2[i - r1 + 1][j - c1 + 1];
		}
	}
}

void operate(vector<int>& v) {
	reset();
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		pair<pair<int, int>, int> x = op[*it];
		rotation(x.first.first, x.first.second, x.second);
	}

	int res = 99999999;
	for (int i = 1; i <= n; i++) {
		int row = 0;
		for (int j = 1; j <= m; j++) {
			row += cp[i][j];
		}
		res = min(res, row);
	}
	ans = min(ans, res);

}

void func(vector<int>& v) {
	if (v.size() == k) {
		operate(v);
		return;
	}

	for (int i = 1; i <= k; i++) {
		if (contain(v, i)) {
			continue;
		}
		else {
			v.push_back(i);
			func(v);
			v.erase(--v.end());
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	for (int i = 1; i <= k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		op[i].first.first = a, op[i].first.second = b, op[i].second = c;
	}

	vector<int> v;
	func(v);
	
	cout << ans << '\n';
}