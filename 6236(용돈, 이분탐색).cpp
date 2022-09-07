#include<iostream>

using namespace std;

int N, M;
int day[100000];

int main(void) {
	cin >> N >> M;

	int left = 0;
	int right = 0;
	for (int i = 0; i < N; i++) {
		cin >> day[i];
		right += day[i];
	}

	while (left + 1 < right) {
		int mid = (left + right) / 2;
		int m = 0;
		int money = 0;
		bool flag = true;

		for (int i = 0; i < N; i++) {
			if (day[i] > money) {
				money = mid;
				m++;
				if (money < day[i]) {
					flag = false;
					break;
				}
				money -= day[i];
			}
			else {
				money -= day[i];
			}
		}

		if (m > M) flag = false;

		if (flag) {
			right = mid;
		}
		else {
			left = mid;
		}
	}

	cout << right << endl;
}