#include<iostream>
#include<algorithm>

using namespace std;

long long a, b;

long long gcd(long long a, long long b) {
	if (a < b) {
		swap(a, b);
	}

	long long n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	long long r = gcd(a, b);

	while (r--) cout << 1;

	return 0;
}