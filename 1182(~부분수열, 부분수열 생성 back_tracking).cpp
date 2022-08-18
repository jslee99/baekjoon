#include<iostream>


using namespace std;
int N, S;
int seq[20];
int cnt = 0;
int idx_lst[20];

void calc(int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += seq[idx_lst[i]];
	}
	if (sum == S)
		cnt++;
}

void back_track(int before_idx, int depth, int len) {
	if (depth == len) {
		calc(len);
		return;
	}

	for (int i = before_idx + 1; i < N; i++) {
		idx_lst[depth] = i;
		back_track(i, depth + 1, len);
	}
}

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> seq[i];

	for (int i = 1; i <= N; i++) back_track(-1, 0, i);

	cout << cnt << endl;
}
