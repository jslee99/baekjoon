#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int* s = (int*)malloc(n * sizeof(int));
	int* l = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	l[n - 1] = 1;
	int* temp;
	for (int i = n - 2; i > -1; i--) {
		temp = (int*)malloc(n * sizeof(int));
		for (int j = i + 1; j < n; j++) {
			if (s[j] <= s[i]) {
				temp[j] = 0;
			}
			else {
				temp[j] = l[j];
			}
		}
		int max = 0;
		for (int j = i + 1; j < n; j++) {
			if (temp[j] > max) {
				max = temp[j];
			}
		}
		l[i] = max + 1;
		free(temp);
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < l[i]) {
			max = l[i];
		}
	}
	printf("%d\n", max);

	free(s);
	free(l);
}