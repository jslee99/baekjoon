#include<stdio.h>
#include<stdlib.h>


int main(void) {
	int n;
	scanf("%d", &n);
	int* s = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	int* m = (int*)malloc(n * sizeof(int));
	m[0] = s[0];
	int max = m[0];
	for (int i = 1; i < n; i++) {
		if (m[i - 1] < 0) {
			m[i] = s[i];
		}
		else {
			m[i] = m[i - 1] + s[i];
		}

		if (max < m[i]) {
			max = m[i];
		}
	}
	printf("%d\n", max);
}