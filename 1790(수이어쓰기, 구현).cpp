#include<iostream>
#include<cmath>
#include<string>

using namespace std;

long long k, n;

int main() {
	cin >> n >> k;

	long long x = 1;
	long long y = 9;
	
	while (k > y * x) {
		k = k - y * x;
		x++;
		y = y * 10;
	}

	long long a = ceil((double)k / (double)x);
	long long b = k % x;
	b = b - 1;
	if (b < 0) b = x - 1;

	long long m = (long long)pow(10, x - 1) + (a - 1);

	string s = to_string(m);

	if (m > n) {
		cout << -1;
	}
	else {
		cout << s[b];
	}
}