#include<iostream>
#include<algorithm>

using namespace std;
unsigned long long desk[100000];
int N;
unsigned long long M;

bool can(unsigned long long mid) {
	unsigned long long capacity = 0;

	for (int i = 0; i < N; i++) {
		capacity += mid / desk[i];
	}

	if (capacity >= M) return true;
	else return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> desk[i];
	}

	sort(desk, desk + N);

	unsigned long long left, right, mid;
	//left = 0, right = 1000000000000000000; -> ¿ÖÆ²¸²?
	left = 0, right = desk[N - 1] * M;

	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (can(mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}

	cout << right << endl;
}