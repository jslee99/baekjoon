#include<iostream>
#include<cmath>

using namespace std;

int T;

int main(void) {
	cin >> T;
	while (T--) {
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) cout << -1 << endl;
			else cout << 0 << endl;
		}
		else {
			double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			if (dist > r1 + r2) {
				cout << 0 << endl;
			}
			else if (dist == r1 + r2) {
				cout << 1 << endl;
			}
			else {
				if (r1 < r2) {
					swap(x1, x2), swap(y1, y2), swap(r1, r2);
				}

				if (dist + r2 > r1) {
					cout << 2 << endl;
				}
				else if (dist + r2 == r1) {
					cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
		}
	}
}