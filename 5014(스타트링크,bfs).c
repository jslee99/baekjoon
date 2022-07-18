#include<stdio.h>

int F, S, G, U, D;
int building[1000001];
int q[1000000];
int tail, head;

int main(void) {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	for (int i = 1; i <= F; i++) {
		building[i] = -1;
	}
	tail = 0, head = 0;
	building[S] = 0;
	q[tail] = S;
	tail++;
	while (tail != head) {
		int cur = q[head];
		head++;
		if (cur + U <= F && building[cur + U] == -1) {
			building[cur + U] = building[cur] + 1;
			q[tail] = cur + U;
			tail++;
		}
		if (cur - D >= 1 && building[cur - D] == -1) {
			building[cur - D] = building[cur] + 1;
			q[tail] = cur - D;
			tail++;
		}
	}
	if (building[G] == -1) {
		printf("use the stairs\n");
	}
	else {
		printf("%d\n", building[G]);
	}

}


