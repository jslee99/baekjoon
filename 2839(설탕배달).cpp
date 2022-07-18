#include<iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int count = 0;
	while (n % 5 != 0 && n > 0) {
		n -= 3;
		count++;
	}
	if (n >= 0) {
		count += n / 5;
	}
	else {
		count = -1;
	}
	printf("%d", count);
}