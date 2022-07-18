#include<stdio.h>
#include<stdlib.h>

int map[8][8];//-1:watch
int copy[8][8];
int cctv_num = 0;
int M, N;
int res = 987654321;

struct CCTV {
	int mode;
	int dir;//0 1 2 3
	int x, y;
};

struct CCTV* cctvs[8];

void update(int x, int y, int dir) {
	switch (dir) {
	case 0:
		x--;
		while (map[x][y] != 6 && x >= 0) {
			if (map[x][y] == 0) {
				map[x][y] = -1;
			}
			x--;
		}
		break;
	case 1:
		y++;
		while (map[x][y] != 6 && y < N) {
			if (map[x][y] == 0) {
				map[x][y] = -1;
			}
			y++;
		}
		break;
	case 2:
		x++;
		while (map[x][y] != 6 && x < M) {
			if (map[x][y] == 0) {
				map[x][y] = -1;
			}
			x++;
		}
		break;
	case 3:
		y--;
		while (map[x][y] != 6 && y >= 0) {
			if (map[x][y] == 0) {
				map[x][y] = -1;
			}
			y--;
		}
		break;
	}
}


void comb(int idx) {
	if (idx < cctv_num) {
		for (int i = 0; i < 4; i++) {
			cctvs[idx]->dir = i;
			comb(idx + 1);
		}
	}
	else {
		for (int i = 0; i < cctv_num; i++) {
			switch (cctvs[i]->mode) {
			case 1:
				//update(x,y,dir)
				update(cctvs[i]->x, cctvs[i]->y, cctvs[i]->dir);
				break;
			case 2:
				update(cctvs[i]->x, cctvs[i]->y, cctvs[i]->dir);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 2) % 4);
				break;
			case 3:
				update(cctvs[i]->x, cctvs[i]->y, cctvs[i]->dir);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 1) % 4);
				break;
			case 4:
				update(cctvs[i]->x, cctvs[i]->y, cctvs[i]->dir);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 1) % 4);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 2) % 4);
				break;
			case 5:
				update(cctvs[i]->x, cctvs[i]->y, cctvs[i]->dir);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 1) % 4);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 2) % 4);
				update(cctvs[i]->x, cctvs[i]->y, (cctvs[i]->dir + 3) % 4);
				break;
			}
		}
		// update res, min;
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					cnt++;
				}
			}
		}
		if (res > cnt)
			res = cnt;
		//clear
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == -1)
					map[i][j] = 0;
			}
		}
	}
	return;
}

int main(void) {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctvs[cctv_num] = (struct CCTV*)malloc(sizeof(struct CCTV));
				cctvs[cctv_num]->mode = map[i][j];
				cctvs[cctv_num]->x = i, cctvs[cctv_num]->y = j;
				cctv_num++;
			}
		}
	}
	comb(0);
	printf("%d\n", res);


}