#include<stdio.h>
#include<stdlib.h>

int liquid[100000];
int start, end;
int N;
int min_abs = 2000000001;
int idx1, idx2;

int comp(int* a, int* b) {
	return *a - *b;
}


int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &liquid[i]);
	}
	qsort(liquid, N, sizeof(int), comp);
	start = 0, end = N - 1;
	while (start < end) {
		if (min_abs > abs(liquid[start] + liquid[end]))
			min_abs = abs(liquid[start] + liquid[end]), idx1 = start, idx2 = end;

		if (min_abs == 0)
			break;

		if (liquid[start] + liquid[end] < 0)
			start++;
		else
			end--;
	}
	printf("%d %d", liquid[idx1], liquid[idx2]);
}

