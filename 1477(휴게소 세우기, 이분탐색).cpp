#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int n, m, l;
vector<int> v;
vector<int> d;
int ans;

bool check(int x) {
	int cnt = 0;
	for (int i = 0; i < d.size(); i++) {
		if (d[i] % x == 0) {
			cnt += d[i] / x - 1;
		}
		else {
			cnt += d[i] / x;
		}	
	}

	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	v.push_back(0), v.push_back(l);
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++) {
		d.push_back(v[i + 1] - v[i]);
	}

	int cnt = 0;
	for (int i = 0; i < d.size(); i++) {
		cnt += d[i] - 1;
	}
	if (cnt <= m) {
		cout << 1;
		exit(0);
	}

	int _left = 1, _right = 1000;
	while (_left + 1 < _right) {
		int mid = (_left + _right) / 2;
		if (check(mid)) {
			_right = mid;
		}
		else {
			_left = mid;
		}
	}

	cout << _right;

	return 0;
}