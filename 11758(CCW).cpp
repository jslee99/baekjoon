#include<iostream>

using namespace std;

int main() {
	int x1, y1;
	int x2, y2;
	int x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int res = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
	if (res < 0) {
		cout << 1 << '\n';
	}
	else if (res == 0) {
		cout << 0 << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}