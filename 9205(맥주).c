#include<stdio.h>
#include<stdlib.h>

int t;
int n;
int loc[102][3];// [0]:house [n + 1]:festival [1 ~ n]:store [][3]:visit
int temp1, temp2;

void bfs(int s_index) {
	loc[s_index][2] = 1;
	for (int i = 0; i < n + 2; i++) {
		if (loc[i][2] == -1 && abs(loc[i][0] - loc[s_index][0]) + abs(loc[i][1] - loc[s_index][1]) <= 1000) {
			bfs(i);
		}
	}
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &temp1, &temp2);
			loc[i][0] = temp1, loc[i][1] = temp2, loc[i][2] = -1;
		}
		bfs(0);
		if (loc[n + 1][2] == 1) {
			printf("happy\n");
		}
		else {
			printf("sad\n");
		}
	}
}