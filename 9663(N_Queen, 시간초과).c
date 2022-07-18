#include<stdio.h>

int board[15][15];
int n;
int dm[8] = { -1,-1,-1,0,1,1,1,0 };
int dn[8] = { -1,0,1,1,1,0,-1,-1 };
int cnt = 0;

void N_Queen(int col) {
	if (col < n - 1) {
		for (int i = 0; i < n; i++) {//i : row
			if (board[i][col] == -1) {
				board[i][col] = col;
				int new_m, new_n;
				for (int j = 1; j < n; j++) {
					for (int k = 0; k < 8; k++) {
						new_m = i + j * dm[k], new_n = col + j * dn[k];
						if (new_m < n && new_m >= 0 && new_n < n && new_n >= 0 && board[new_m][new_n] == -1) {
							board[new_m][new_n] = col;
						}
					}
				}
				N_Queen(col + 1);
				board[i][col] = -1;
				for (int j = 1; j < n; j++) {
					for (int k = 0; k < 8; k++) {
						new_m = i + j * dm[k], new_n = col + j * dn[k];
						if (new_m < n && new_m >= 0 && new_n < n && new_n >= 0 && board[new_m][new_n] == col) {
							board[new_m][new_n] = -1;
						}
					}
				}
			}
			//no else continue
		}
	}
	else {//when col == n - 1
		for (int i = 0; i < n; i++) {
			if (board[i][col] == -1) {
				cnt++;
			}
			//no else
		}
	}
	return;
}


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = -1;
		}
	}
	N_Queen(0);
	printf("%d\n", cnt);
}
