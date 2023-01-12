#include<iostream>

using namespace std;

int need_money[10000];
int N, M;

bool func(int upper_bound) {
	int total = 0;
	for (int i = 0; i < N; i++) {
		if (need_money[i] > upper_bound) {
			total += upper_bound;
		}
		else {
			total += need_money[i];
		}
	}

	return total <= M;
}

int main(void) {
	cin >> N;
	int total_money = 0;
	int max_money = 0;
	for (int i = 0; i < N; i++) {
		cin >> need_money[i];
		total_money += need_money[i];
		max_money = max(max_money, need_money[i]);
	}
	cin >> M;

	if (total_money <= M) {
		cout << max_money << endl;
		return 0;
	}

	int left = 1, right = 100000, mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (func(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << left << endl;
}