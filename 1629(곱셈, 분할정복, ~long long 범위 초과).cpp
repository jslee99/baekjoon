#include<iostream>

using namespace std;
int A, B, C;

int power_mod(int base, int exp, int mod) {
	if (exp == 1) {
		return base % mod;
	}

	long long temp;
	if (exp % 2 == 1) {
		int half = power_mod(base, exp / 2, mod);
		temp = (long long)half * (long long)half;
		temp = temp % mod;
		temp = temp * (long long)base;
		return (int)(temp % (long long)mod);
	}
	else {
		int half = power_mod(base, exp / 2, mod);
		temp = (long long)half * (long long)half;
	}
	return (int)(temp % (long long)mod);
}

int main(void) {
	cin >> A >> B >> C;
	cout << power_mod(A, B, C) << endl;
}