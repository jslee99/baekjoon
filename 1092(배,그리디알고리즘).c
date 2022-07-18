#include<stdio.h>
#include<stdlib.h>

int N;
int crane[50];
int M;
int box[10000];
int time = 0;
int box_idx;
int crane_idx;
int move_box[10000] = { 0, };
int cnt = 0;

int comp(int* a, int* b) {
	return *a - *b;
}

int main(void) {
	scanf("%d", &N);
	crane_idx = N - 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &crane[i]);
	}
	scanf("%d", &M);
	box_idx = M - 1;
	for (int i = 0; i < M; i++) {
		scanf("%d", &box[i]);
	}
	qsort(crane, N, sizeof(int), comp);
	qsort(box, M, sizeof(int), comp);
	if (box[M - 1] > crane[N - 1]) {
		printf("-1\n");
		return 0;
	}
	
	while (cnt < M) {
		crane_idx = N - 1;
		box_idx = M - 1;
		while (box_idx > -1 && crane_idx > -1) {
			if (move_box[box_idx] == 0 && crane[crane_idx] >= box[box_idx]) {
				cnt++;
				move_box[box_idx] = 1;
				crane_idx--;
				box_idx--;
			}
			else {
				box_idx--;
			}
		}
		time++;
	}



	printf("%d\n", time);
}



