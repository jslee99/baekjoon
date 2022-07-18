#include<stdio.h>
#include<stdlib.h>

void func(const int* nums, int res[], int p, int r, int tail) {
	/*if (tail == 4) {
		for (int i = p; i <= r; i++) {
			res[5] = nums[i];
			for (int i = 0; i < 6; i++) {
				printf("%d ", res[i]);
			}
			printf("\n");
		}
	}*/
	if (tail == 5) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i <= r - p + tail - 4; i++) {//(r - p + 1) - (5 - tail) 
			res[tail + 1] = nums[p + i];
			func(nums, res, p + i + 1, r, tail + 1);
		}
	}
}
int main(void) {
	int k;
	scanf("%d", &k);
	int* nums;
	int res[6];
	while (k != 0) {
		nums = (int*)malloc(sizeof(int) * k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &nums[i]);
		}
		func(nums, res, 0, k - 1, -1);
		printf("\n");
		
		scanf("%d", &k);
		free(nums);
	}
}