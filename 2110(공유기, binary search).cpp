#include<iostream>
#include<algorithm>

using namespace std;

int N, C;
int house[200000];

bool is_can(int x) {
	int cnt = 1;
	int dist_sum = 0;
	for (int i = 1; i < N; i++) {
		dist_sum += house[i] - house[i - 1];
		if (dist_sum >= x) {
			cnt++;
			dist_sum = 0;
		}
	}
	return cnt >= C;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> house[i];

	sort(house, house + N);

	int _left = 1, _right = 1000000001; // can, cant
	int _mid;
	while (_left + 1 < _right) {
		_mid = (_left + _right) / 2;
		if (is_can(_mid)) {
			_left = _mid;
		}
		else {
			_right = _mid;
		}
	}

	cout << _left << endl;
}