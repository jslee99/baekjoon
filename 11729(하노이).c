#include<stdio.h>

void hanoi(int n, int from, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (i != from && i != to) {
				hanoi(n - 1, from, i);
				printf("%d %d\n", from, to);
				hanoi(n - 1, i, to);
				break;
			}
		}
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc((n + 1) * sizeof(int));
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = 2 * a[i - 1] + 1;
	}
	printf("%d\n",a[n]);
	hanoi(n, 1, 3);
}