#include<stdio.h>
#include<stdlib.h>

int max_subarray(const int* s,int p,int r) {
	if (p == r) {
		return s[p];
	}
	int left_max_sub, right_max_sub, middle_max_sub;
	int q = (p + r) / 2;
	left_max_sub = max_subarray(s, p, q);
	right_max_sub = max_subarray(s, q + 1, r);
	int left_sum, right_sum, left_max_sum, right_max_sum;
	left_sum = s[q];
	right_sum = s[q + 1];
	left_max_sum = s[q];
	right_max_sum = s[q + 1];
	for (int i = q - 1; i > -1; i--) {
		left_sum += s[i];
		if (left_sum > left_max_sum) {
			left_max_sum = left_sum;
		}
	}
	for (int i = q + 2; i < r + 1; i++) {
		right_sum += s[i];
		if (right_sum > right_max_sum) {
			right_max_sum = right_sum;
		}
	}
	middle_max_sub = left_max_sum + right_max_sum;
	if (left_max_sub > middle_max_sub && left_max_sub > right_max_sub) {
		return left_max_sub;
	}
	else if (right_max_sub > middle_max_sub && right_max_sub > left_max_sub) {
		return right_max_sub;
	}
	else {
		return middle_max_sub;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	int* s = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	printf("%d\n", max_subarray(s, 0, n - 1));
}