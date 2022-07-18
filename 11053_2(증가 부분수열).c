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
	l[0] = 1;
	int max_length = 1;
	for (int i = 1; i < n; i++) {
		int max = 1;
		for (int j = 0; j < i; j++) {
			if (s[j] < s[i]) {
				if (max < l[j] + 1) {
					max = l[j] + 1;
				}
			}
		}
		l[i] = max;
		if (max_length < l[i]) {
			max_length = l[i];
		}		
	}
	printf("%d\n", max_length);
	

	free(s);
	free(l);
}