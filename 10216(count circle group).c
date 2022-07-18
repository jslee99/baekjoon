#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int T;
int N;
int point[5000][3];//x,y,R
int a[5000][5000];
int visit[5000];
int cnt;

void bfs(int i) {
	visit[i] = 1;
	for (int j = 0; j < N; j++) {
		if (a[i][j] == 1 && visit[j] == 0) {
			bfs(j);
		}
	}
}

int main(void) {
	scanf("%d", &T);
	while (T--) {
		cnt = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			visit[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &point[i][0], &point[i][1], &point[i][2]);
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				double x = (double)(point[i][0] - point[j][0]);
				double y = (double)(point[i][1] - point[j][1]);
				double dist = sqrt(x * x + y * y);
				if (dist <= (double)point[i][2] + (double)point[j][2]) {
					a[i][j] = 1, a[j][i] = 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (visit[i] == 0) {
				bfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
		


	}
}


