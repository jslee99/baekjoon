#include<stdio.h>

int n, k;
int a[100001];
int q[100001];
int tail = 0, head = 0;

int move(int x, int i) {
	if (i == 0) {
		return x - 1;
	}
	else if (i == 1) {
		return x + 1;
	}
	else {
		return 2 * x;
	}
}

void dfs() {
	int x;
	int new_x;
	while (!(head == tail)) {
		x = q[head];
		head++;
		for (int i = 0; i < 3; i++) {
			new_x = move(x, i);
			if (new_x <= 100000 && new_x >= 0 && a[new_x] == -1) {
				a[new_x] = a[x] + 1;
				q[tail] = new_x;
				tail++;
			}
			if (new_x == k) {
				break;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 100001; i++) {
		a[i] = -1;
	}
	scanf("%d %d", &n, &k);
	a[n] = 0;
	q[tail] = n;
	tail++;
	dfs();
	printf("%d\n", a[k]);
}