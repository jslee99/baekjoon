#include<iostream>
#include<climits>

using namespace std;

long long a, b;
bool p[10000005];
long long ans = 0;

int main() {
	cin >> a >> b;

	for (int i = 1; i <= 10000000; i++) p[i] = true;

	p[1] = false;

	for (int i = 2; i <= 10000000; i++) {
		if (!p[i]) continue;

		for (int j = 2; i * j <= 10000000; j++) {
			p[i * j] = false;
		}
	}

	for (long long i = 2; i <= 10000000; i++) {
		if (!p[i]) continue;

		long long x = i * i;
		while (x <= b) {
			if (a <= x) ans++;

			if (LLONG_MAX / i < x) break;

			x = x * i;
		}
	}

	cout << ans;

	return 0;
}