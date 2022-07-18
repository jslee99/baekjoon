#include<stdio.h>

int map[100][100];// -1:apple 0:space 1:snake
int N, K, L;
int inf_time[100];
char inf_dir[100];
int head1 = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dir = 1;// 0 1 2 3
int snake[10000][2];
int tail2 = 0, head2 = 0;//queue
int time = 0;

int main(void) {
	scanf("%d", &N);
	scanf("%d", &K);
	while (K--) {
		int x, y;
		scanf("%d  %d", &x, &y);
		map[x - 1][y - 1] = -1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int x;
		char ch;
		scanf("%d", &x);
		getchar();
		scanf("%c", &ch);
		inf_time[i] = x, inf_dir[i] = ch;
	}
	map[0][0] = 1;
	snake[tail2][0] = 0, snake[tail2][1] = 0;
	tail2++;
	time++;
	int new_x = 0, new_y = 1;
	while (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && map[new_x][new_y] != 1) {
		if (map[new_x][new_y] == -1) {
			snake[tail2][0] = new_x, snake[tail2][1] = new_y;
			tail2++;
			map[new_x][new_y] = 1;
		}
		else {// == 0
			snake[tail2][0] = new_x, snake[tail2][1] = new_y;
			tail2++;
			map[new_x][new_y] = 1;
			map[snake[head2][0]][snake[head2][1]] = 0;
			head2++;
		}
		//next move
		if (inf_time[head1] == time) {//change direction
			if (inf_dir[head1] == 'L')
				dir = (dir + 3) % 4;
			else
				dir = (dir + 1) % 4;
			head1++;
		}
		new_x = snake[tail2 - 1][0] + dx[dir], new_y = snake[tail2 - 1][1] + dy[dir];
		time++;
	}
	printf("%d", time);
}