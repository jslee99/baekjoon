#include<iostream>
#include<algorithm>

using namespace std;
int liquid[100000];
int N;
pair<int, int> ans;
int criteria_idx;

void solve() {
	int _left = 0, _right = N - 1;
	while (_left + 1 < _right) {
		int _mid = (_left + _right) / 2;
		if (liquid[_mid] < 0) {
			_left = _mid;
		}
		else {
			_right = _mid;
		}
	}
	criteria_idx = _right;
}

int main(void) {
	cin >> N;
	ans.first = 1000000000, ans.second = 1000000000;
	for (int i = 0; i < N; i++) cin >> liquid[i];
	sort(liquid, liquid + N);
	if (liquid[0] >= 0) {
		ans.first = liquid[0], ans.second = liquid[1];
		cout << ans.first << " " << ans.second << endl;
		exit(0);
	}
	else if (liquid[N - 1] < 0) {
		ans.first = liquid[N - 2], ans.second = liquid[N - 1];
		cout << ans.first << " " << ans.second << endl;
		exit(0);
	}
	else {
		solve();
		if (N - criteria_idx > 1) {
			if (abs(liquid[criteria_idx] + liquid[criteria_idx + 1]) <= abs(ans.first + ans.second)) {
				ans.first = liquid[criteria_idx], ans.second = liquid[criteria_idx + 1];
			}
		}

		if (criteria_idx > 1) {
			if (abs(liquid[criteria_idx - 1] + liquid[criteria_idx - 2]) <= abs(ans.first + ans.second)) {
				ans.first = liquid[criteria_idx - 2], ans.second = liquid[criteria_idx - 1];
			}
		}
	}
	//-100 1 2 �ΰ�� 1,2 �������̴� -100, 2�� �ƴϴ�. 
	//�� ������ ���� ����� ���� ���� �� �ְ�(criteria - 1, criteria - 2 )or(criteria, criteria + 1) Ȥ�� �ٸ� ����� ���� ���� �� �ִ�(�� ���� ���� �̺�Ž���� �̿��Ѵ�.)

	for (int i = 0; i < criteria_idx; i++) {
		if (abs(liquid[i]) <= liquid[criteria_idx]) {
			if (abs(0 - (liquid[i] + liquid[criteria_idx])) <= abs(0 - (ans.first + ans.second))) {
				ans.first = liquid[i];
				ans.second = liquid[criteria_idx];
			}
		}
		else if (abs(liquid[i]) > liquid[N - 1]) {
			if (abs(0 - (liquid[i] + liquid[N - 1])) <= abs(0 - (ans.first + ans.second))) {
				ans.first = liquid[i];
				ans.second = liquid[N - 1];
			}
		}
		else {
			int _left = criteria_idx, _right = N - 1;
			while (_left + 1 < _right) {
				int _mid = (_left + _right) / 2;
				if (liquid[_mid] < abs(liquid[i])) {
					_left = _mid;
				}
				else {
					_right = _mid;
				}
			}

			if (abs(0 - (liquid[i] + liquid[_left])) <= abs(0 - (ans.first + ans.second))) {
				ans.first = liquid[i];
				ans.second = liquid[_left];
			}

			if (abs(0 - (liquid[i] + liquid[_right])) <= abs(0 - (ans.first + ans.second))) {
				ans.first = liquid[i];
				ans.second = liquid[_right];
			}
		}
	}

	cout << ans.first << " " << ans.second << endl;
}
