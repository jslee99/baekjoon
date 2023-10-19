#include<iostream>
#include<algorithm>

using namespace std;

int n, t;
int a[100005];

bool check(int m) {
	int s = 0;//time sum
	int x = 0;//°³¼ö

	for (int i = 1; i <= n; i++) {
		if (a[i] > m) return false;
	}

	for (int i = 1; i <= n; i++) {
		if (s == 0)x++;

		s += a[i];

		if(s > m){
			s = 0;
			i--;
		}
		else if (s == m) {
			s = 0;
		}
		else {

		}
	}

	return x <= t;
}

int main() {

	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int l = 0, r = 1000000000;
	int m;
	while (l + 1 < r) {
		m = (l + r) / 2;
		if (check(m)) {
			r = m;
		}
		else {
			l = m;
		}
	}

	cout << r;

	return 0;
}