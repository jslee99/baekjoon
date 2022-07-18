#include<stdio.h>

int a[30][30][30];//-1:. -2:#
int L, R, C;
int q[27000][3];//l, r, c
int tail = 0, head = 0;
int s_l, s_r, s_c;
int e_l, e_r, e_c;
int dl[6] = { 0, 0, 0, 0, 1, -1 };
int dr[6] = { -1, 0, 1, 0, 0, 0 };
int dc[6] = { 0, 1, 0, -1, 0, 0 };

int main(void) {
	while (1) {
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0) {
			break;
		}
		char buf[30];
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				scanf("%s", &buf);
				for (int k = 0; k < C; k++) {
					if (buf[k] == '.') {
						a[i][j][k] = -1;
					}
					else if(buf[k] == '#') {
						a[i][j][k] = -2;
					}
					else {
						if (buf[k] == 'S') {
							s_l = i, s_r = j, s_c = k;
							a[i][j][k] = -1;
						}
						else {
							e_l = i, e_r = j, e_c = k;
							a[i][j][k] = -1;
						}
					}
				}
			}
		}
		q[tail][0] = s_l, q[tail][1] = s_r, q[tail][2] = s_c;
		tail++;
		a[s_l][s_r][s_c] = 0;
		int l, r, c;
		int new_l, new_r, new_c;
		while (tail != head) {
			l = q[head][0], r = q[head][1], c = q[head][2];
			head++;
			for (int i = 0; i < 6; i++) {
				new_l = l + dl[i], new_r = r + dr[i], new_c = c + dc[i];
				if (new_l >= 0 && new_l < L && new_r >= 0 && new_r < R && new_c >= 0 && new_c < C && a[new_l][new_r][new_c] == -1) {
					a[new_l][new_r][new_c] = a[l][r][c] + 1;
					q[tail][0] = new_l, q[tail][1] = new_r, q[tail][2] = new_c;
					tail++;
				}
			}
		}

		if (a[e_l][e_r][e_c] == -1) {
			printf("Trapped!\n");
		}
		else {
			printf("Escaped in %d minute(s).\n", a[e_l][e_r][e_c]);
		}
	}


	return 0;
}



