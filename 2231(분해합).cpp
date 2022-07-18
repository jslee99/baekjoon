#include<iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	/*for (int i = 1; i < 10; i++) {
		if (n == i + i) {
			printf("%d", i);
			return 0;
		}
	}*/
	for (int a = 1; a <= 999999; a++) {//a,x:생성자,sum:분해합
		int x = a;
		int sum = x;
		for (int i = 0; i < 6; i++) {
			sum += x % 10;
			x = x / 10;//23 /10 == 2 (no type conversion)
		}
		if (sum == n) {
			printf("%d", a);
			return 0;
		}
	}
	printf("%d", 0);
}