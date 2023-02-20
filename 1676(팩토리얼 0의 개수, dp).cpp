#include<iostream>

using namespace std;
int N;
int num_2[501];
int num_5[501];

void dp() {
	num_2[1] = 0;
	num_5[1] = 0;

	for (int i = 2; i <= 500; i++) {
		int x = i, y = i;
		num_2[i] = num_2[i - 1], num_5[i] = num_5[i - 1];

		while (x % 2 == 0) {
			x = x / 2;
			num_2[i]++;
		}

		while (y % 5 == 0) {
			y = y / 5;
			num_5[i]++;
		}
	}
}

int main() {
	cin >> N;

	dp();

	cout << min(num_2[N], num_5[N]) << endl;
}