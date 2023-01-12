#include<iostream>

using namespace std;

int diamond_num[300000];
int N, M;

bool func(int score) {
	long long need_N = 0;
	for (int i = 0; i < M; i++) {
		if (diamond_num[i] % score) {
			need_N += (long long)(diamond_num[i] / score + 1);
		}
		else {
			need_N += (long long)(diamond_num[i] / score);
		}
	}
	return need_N <= (long long)N;
}

int main(void) {
	cin >> N >> M;
	long long total_num = 0;
	int max_num = 0;
	for (int i = 0; i < M; i++) {
		cin >> diamond_num[i];
		total_num += (long long)diamond_num[i];
		max_num = max(max_num, diamond_num[i]);
	}

	if (total_num <= (long long)N) {
		cout << 1 << endl;
		return 0;
	}

	//1 : impossible  max_num :: possible
	int left = 1, right = max_num, mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (func(mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << right << endl;
}