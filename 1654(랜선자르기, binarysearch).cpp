#include<iostream>
#include<limits>

using namespace std;
unsigned int _left = 1, _right = (unsigned int)numeric_limits<int>::max() + 1, _mid;
int K, N;
unsigned int rope[10000];

int main(void){
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> rope[i];
	}


	while (_left + 1 < _right) {
		_mid = (_left + _right) / 2;
		long long total_N = 0;
		for (int i = 0; i < K; i++) {
			total_N += (long long)(rope[i] / _mid);
		}
		if (total_N < (long long)N) {
			_right = _mid;
		}
		else {
			_left = _mid;
		}
	}

	cout << _left << endl;
}