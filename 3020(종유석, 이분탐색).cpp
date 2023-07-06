#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, H;
vector<int> _low;
vector<int> _high;
int dp[500005];

int num_of_low(int k, const vector<int>& vec) {
	//left < k   k <= right
	int _left = 0;
	int _right = (int)vec.size() - 1;
	if (k <= vec[_left]) {
		return _right + 1;
	}
	if (vec[_right] < k) {
		return 0;
	}

	int _mid;
	while (_left + 1 < _right) {
		_mid = (_left + _right) / 2;
		if (vec[_mid] < k) {
			_left = _mid;
		}
		else {
			_right = _mid;
		}
	}

	return (int)vec.size() - _right;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &H);

	for (int i = 0; i < N; i++) {
		int a;
		if (i % 2 == 0) {
			scanf("%d", &a);
			_low.push_back(a);
		}
		else {
			scanf("%d", &a);
			_high.push_back(a);
		}
	}

	sort(_low.begin(), _low.end());
	sort(_high.begin(), _high.end());

	int _min = 999999;
	int cnt = 0;
	for (int h = 1; h <= H; h++) {//h == 1 : 0 ~ 1
		dp[h] = num_of_low(h, _low) + num_of_low(H - h + 1, _high);
		_min = min(_min, dp[h]);
	}

	for (int h = 1; h <= H; h++) {
		if (dp[h] == _min) {
			cnt++;
		}
	}

	printf("%d %d\n", _min, cnt);

	return 0;
}

/*
#include<algorithm>

char buf[100[;
scanf("%s", &buf);
*/