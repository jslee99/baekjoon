#include<stdio.h>

long long a, b;

long long gcd(long long x, long long y) {
	if (y > x) {
		long long temp = x;
		x = y;
		y = temp;
	}

	if (y == 0)
		return x;

	return gcd(y, x % y);
}

long long min_sum = 98765432;
long long res1, res2;

int main(void) {
	scanf("%lld %lld", &a, &b);
	for (long long i = 1; i * i <= a * b; i++) {
		if (a * b % i == 0 && gcd(a * b / i, i) == a) {
			res1 = i;
			res2 = a * b / i;
		}
	}
	printf("%lld %lld", res1, res2);
	return 0;
}