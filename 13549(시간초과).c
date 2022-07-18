#include<stdio.h>
#include<stdlib.h>

int map[100001];
int N, K;

void dfs(int idx, int sec) {//teleport
	map[idx] = sec;
	if (idx == K) {
		printf("%d\n", sec);
		exit(0);
	}
	if (idx * 2 <= 100000 && map[idx * 2] == -1)
		dfs(idx * 2, sec);
}

int main(void) {
	for (int i = 0; i <= 100000; i++) {
		map[i] = -1;
	}
	scanf("%d %d", &N, &K);
	dfs(N, 0);
	int x = 0;
	while (1) {
		for (int i = 0; i <= 100000; i++) {
			if (map[i] == x) {
				if (i - 1 >= 0 && map[i - 1] == -1) {
					map[i - 1] = x + 1;
					if (i - 1 == K) {
						printf("%d\n", x + 1);
						exit(0);
					}
					dfs(i - 1, x + 1);
				}
				if (i + 1 <= 100000 && map[i + 1] == -1) {
					map[i + 1] = x + 1;
					if (i + 1 == K) {
						printf("%d\n", x + 1);
						exit(0);
					}
					dfs(i + 1, x + 1);
				}
			}
		}
		x++;
	}
}


