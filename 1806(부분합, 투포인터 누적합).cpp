#include<iostream>

using namespace std;
int sequence[100000];
int start[100000]; // 0 ~ i(include)
int N, S;
int min_len = 100001;
int _left, _right;
int start_idx;

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> sequence[i];

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += sequence[i];
		if (sum >= S) {
			start[i] = 0;//0 ~ i (include)
			_left = 0;
			_right = i;
			break;
		}
		else {
			start[i] = -1;
		}
	}

	if (start[N - 1] == -1) {
		cout << 0 << endl;
		exit(0);
	}
	start_idx = _right;
	sum -= sequence[_right];	

	for (_right; _right < N; _right++) {
		sum += sequence[_right];
		for (_left; _left <= _right; _left++) {
			if (sum - sequence[_left] >= S) {
				sum -= sequence[_left];
				continue;
			}
			else {
				start[_right] = _left;
				break;
			}
		}
	}

	for (int i = start_idx; i < N; i++) min_len = min(min_len, i - start[i] + 1);

	cout << min_len << endl;
}
