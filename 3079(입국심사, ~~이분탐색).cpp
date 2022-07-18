#include<iostream>

using namespace std;

int N;
long long M;
long long check_time[100000];
long long _left = 1000000001, _right = 0;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> check_time[i];
		if (_left > check_time[i])
			_left = check_time[i];
		if (_right < check_time[i])
			_right = check_time[i];
	}
	_right *= M;

	while (_left + 1< _right) {
		long long _mid = (_left + _right) / 2;
		long long total = 0;
		for (int i = 0; i < N; i++) {
			total += _mid / check_time[i];
		}

		if (total >= M) {//시간충분
			_right = _mid;
		}
		else {
			_left = _mid;
		}
	}

	cout << _right << endl;
	//https://www.acmicpc.net/blog/view/109
}