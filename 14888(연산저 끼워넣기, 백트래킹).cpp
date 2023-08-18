#include<iostream>

using namespace std;

int n;
int a[15];
int b[4];
int op[15];
int ma = -1000000001, mi = 1000000001;

void calc() {
	int res = a[0];
	for (int i = 0; i < n - 1; i++) {
		switch (op[i]) {
		case 0:
			res += a[i + 1];
			break;
		case 1:
			res -= a[i + 1];
			break;
		case 2:
			res *= a[i + 1];
			break;
		case 3:
			res /= a[i + 1];
			break;
		}
	}
	ma = max(res, ma);
	mi = min(res, mi);
}

void func(int x) {
	if (x == n - 1) {
		calc();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (b[i] > 0) {
			b[i]--;
			op[x] = i;
			func(x + 1);
			b[i]++;
		}
	}
}

// 0 1 2 3 + - x /
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}

	func(0);

	cout << ma << '\n' << mi << '\n';
}