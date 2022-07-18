#include<iostream>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void) {
	int n;
	scanf_s("%d", &n);
	int max = -1000001;
	int min = 1000001;
	int num;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);
		if (max < num) {
			max = num;
		}
		if (min > num) {
			min = num;
		}
	}
	printf("%d %d", min, max);
}