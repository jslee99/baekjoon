#include<stdio.h>

int res = 0;
char map[12][6];
int cnt = 0;//count in while loop
int q[72][2];//row,col
int visit[12][6];//0 or 1
int tail = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char q2[12];
int tail2 = 0;

void dfs(int x, int y) {
	visit[x][y] = 1;
	q[tail][0] = x, q[tail][1] = y;
	tail++;
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i], new_y = y + dy[i];
		if (new_x >= 0 && new_x < 12 && new_y >= 0 && new_y < 6 && visit[new_x][new_y] == 0 && map[new_x][new_y] == map[x][y])
			dfs(new_x, new_y);
	}
}

int main(void) {
	for (int i = 0; i < 12; i++) {
		char buf[7];
		scanf("%s", buf);
		for (int j = 0; j < 6; j++) {
			map[i][j] = buf[j];
		}
	}
	
	while (1) {
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				visit[i][j] = 0;
		//chainreaction phase
		cnt = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visit[i][j] == 0) {
					if (map[i][j] == '.')
						visit[i][j] = 1;
					else {
						dfs(i, j);
						if (tail > 3) {//chainreaction
							for (int k = 0; k < tail; k++) {
								map[q[k][0]][q[k][1]] = '.';
							}
							cnt++;
							tail = 0;
						}
						else {
							tail = 0;
						}
					}
				}
			}
		}
		
		if (cnt == 0)
			break;
		else
			res++;

		//down phase
		for (int j = 0; j < 6; j++) {
			for (int i = 11; i >= 0; i--) {
				if (map[i][j] != '.') {
					q2[tail2] = map[i][j];
					tail2++;
				}
			}
			for (int i = 0; i < tail2; i++) {
				map[11 - i][j] = q2[i];
			}
			for (int i = tail2; i < 12; i++)
				map[11 - i][j] = '.';
			tail2 = 0;
		}	
	}
	printf("%d\n", res);
}