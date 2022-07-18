#include<stdio.h>
#include<stdlib.h>

int board[14];//board[i]:i번째 열에서 몇번째 행에 퀸이 있는지
int n;
int cnt;

void N_Queen(int col) {
	if (col < n - 1) {
		int check;
		for (int i = 0; i < n; i++) {//i,col
			check = 0;
			for (int j = 0; j < col; j++) {//checking with board[j],j
				if (board[j] == i || col - j == abs(i - board[j])) {
					check = 1;
					break;
				}
			}
			if (check == 1) {
				continue;
			}

			board[col] = i;
			N_Queen(col + 1);
			board[col] = -1;
		}
	}
	else {
		int check;
		for (int i = 0; i < n; i++) {//i,n - 1
			check = 0;
			for (int j = 0; j < col; j++) {
				if (board[j] == i || abs(board[j] - i) == col - j) {
					check = 1;
					break;
				}
			}
			if (check == 0) {
				cnt++;
			}
		}
	}
	return;
}


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		board[i] = -1;
	}
	N_Queen(0);
	printf("%d\n", cnt);
}

