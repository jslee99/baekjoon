#include<iostream>
#include<cmath>

int main(void) {
	/*
	int c = sqrt(5);
	printf("%d", c);
	*/
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	bool check = false;
	int min;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		bool prime = true;
		int x = sqrt(i);
		for (int j = 2; j <= x; j++) {//checking divisor when x ]== 2 ~ root of j
			if (i % j == 0) {
				prime = false;
				break;
			}
		}
		if (i == 1) {
			prime = false;
		}
		if (prime == true) {
			if (check == false) {
				sum += i;
				min = i;
				check = true;
			}
			else {
				sum += i;
			}
		}
	}
	if (sum != 0) {
		printf("%d\n", sum);
		printf("%d\n", min);
	}
	else {
		printf("%d\n", -1);
	}
}