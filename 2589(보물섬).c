#include<stdio.h>

int visit[50][50];
int M, N;
char buf[50];
int q[2500][2];
int tail, head;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int max = -1;

int main(void) {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		scanf("%s", &buf);
		for (int j = 0; j < N; j++) {
			if (buf[j] == 'L') {
				visit[i][j] = -1;
			}
			else {
				visit[i][j] = -2;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == -1) {
				//bfs
				visit[i][j] = 0;
				tail = 0, head = 0;
				q[tail][0] = i, q[tail][1] = j;
				tail++;
				while (tail != head) {
					int x, y;
					x = q[head][0], y = q[head][1];
					head++;
					for (int k = 0; k < 4; k++) {
						int new_x, new_y;
						new_x = x + dx[k], new_y = y + dy[k];
						if (new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && visit[new_x][new_y] == -1) {
							visit[new_x][new_y] = visit[x][y] + 1;
							q[tail][0] = new_x, q[tail][1] = new_y;
							tail++;
							if (visit[new_x][new_y] > max) {
								max = visit[new_x][new_y];
							}
						}
					}
				}
				for (int k = 0; k < M; k++) {
					for (int l = 0; l < N; l++) {
						if (visit[k][l] != -2) {
							visit[k][l] = -1;
						}
					}
				}
			}
		}
	}
	printf("%d\n", max);
}

