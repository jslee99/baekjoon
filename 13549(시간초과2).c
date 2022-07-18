#include<stdio.h>

int map[100001];
int q[100000];
int tail = 0, head = 0;
int N, K;

int main(void) {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= 100000; i++)
		map[i] = -1;
	map[N] = 0;
	q[tail] = N;
	tail++;
	while (tail != head) {
		for (int i = q[head] * 2; i <= 100000; i *= 2) {
			if (map[i] == -1) {
				map[i] = map[q[head]];
				q[tail] = i;
				tail++;
			}
		}
		if (q[head] - 1 >= 0 && map[q[head] - 1] == -1) {
			map[q[head] - 1] = map[q[head]] + 1;
			q[tail] = q[head] - 1;
			tail++;
		}
		if (q[head] + 1 <= 100000 && map[q[head] + 1] == -1) {
			map[q[head] + 1] = map[q[head]] + 1;
			q[tail] = q[head] + 1;
			tail++;
		}
		head++;
	}
	printf("%d\n", map[K]);
}


