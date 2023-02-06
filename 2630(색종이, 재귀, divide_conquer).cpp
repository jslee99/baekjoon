#include<iostream>

using namespace std;
int map[128][129];
int N;

bool is_all_blue(int r, int c, int n) {
	for (int i = r; i < r + n; i++) for (int j = c; j < c + n; j++) if (map[i][j] != 1) return false;
	return true;
}
bool is_all_white(int r, int c, int n) {
	for (int i = r; i < r + n; i++) for (int j = c; j < c + n; j++) if (map[i][j] != 0) return false;
	return true;
}

pair<int, int> func(int r, int c, int n) {
	if (is_all_blue(r, c, n)) {
		return make_pair(0, 1);
	}else if (is_all_white(r, c, n)) {
		return make_pair(1, 0);
	}

	pair<int, int> res;
	res.first = 0, res.second = 0;

	pair<int, int> x;
	x = func(r, c, n / 2);
	res.first += x.first, res.second += x.second;

	x = func(r + n / 2, c, n / 2);
	res.first += x.first, res.second += x.second;

	x = func(r, c + n / 2, n / 2);
	res.first += x.first, res.second += x.second;

	x = func(r + n / 2, c + n / 2, n / 2);
	res.first += x.first, res.second += x.second;
	return res;

}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];

	pair<int, int > ans = func(0, 0, N);
	cout << ans.first << '\n' << ans.second << '\n';
}