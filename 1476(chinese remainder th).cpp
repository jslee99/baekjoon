#include<iostream>
using namespace std;

int main(void) {
	const long m1 = 15, m2 = 28, m3 = 19;
	long a1, a2, a3;
	scanf("%d %d %d", &a1, &a2, &a3);
	const long M1 = m2 * m3, M2 = m1 * m3, M3 = m1 * m2;
	const long y1 = -2, y2 = - 11, y3 = -9;

	long x = (a1 * M1 * y1 + a2 * M2 * y2 + a3 * M3 * y3);
	long m = x % (m1 * m2 * m3);
	m = (m1 * m2 * m3) + m;
	printf("%d", m);
}