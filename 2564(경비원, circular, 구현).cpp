#include <iostream>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int r, c;
int t;

int n, x;
vector<int> v;

int ans = 0;

// 1 ~ n

int convert(int a, int b) {
	switch (a) {
		case 1: {
			return n - b + 1;
			break;
		}
		case 2: {
			return r + b + 1;
			break;
		}
		case 3: {
			return b + 1;
			break;
		}
		case 4: {
			return 2 * r + c + 1 - b;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> r;
	n = r * 2 + c * 2;

	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		v.push_back(convert(a, b));
	}
	int a, b;
	cin >> a >> b;
	x = convert(a, b);

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		int s = x, e = *it;
		if (s > e)
			swap(s, e);

		ans += min(e - s, s + n - e);
	}

	cout << ans << '\n';

	return 0;
}